#include <iostream>
#include <string.h>

using namespace std;

int t, swaps, m[50001];

//Слияние отсортированных массивов a[bleft] ... a[bright] и a[cleft] ... a[cright] в a[bleft] ... a[cright].
//Отметим, что у нас всегда bright + 1 = cleft. Для слияния используем дополнительный массив res.
//Сначала скопируем a[bleft ... bright] в res[0 … len – 1], где len = bright – bleft + 1,
//после чего сольем res[0 … len – 1] и a[cleft ... cright] в a[bleft ... cright].
void merge(int *a, int bleft, int bright, int cleft, int cright)
{
	const int len = bright - bleft + 1;
	int resCur = 0, q = 0, *res = new int[len];
	memcpy(res, a + bleft, len * sizeof(int));
	while (resCur < len && cleft <= cright)
	{
		while (res[q] <= a[cleft] + t && q < len) q++;
		if (res[resCur] <= a[cleft]) a[bleft++] = res[resCur++];
		else a[bleft++] = a[cleft++], swaps += len - q;
	}
	while (resCur < len) a[bleft++] = res[resCur++];
	delete[] res;
}

//Сортируем массив a[left ... right] методом “разделяй и властвуй”. Для этого
//разделим его на две части a[left ... middle] и a[middle + 1 ... right],
//отсортируем отдельно каждую из них, после чего произведем слияние.
void mergeSort(int *a, int left, int right)
{
	if (left >= right) return;
	const int middle = (left + right) / 2;
	mergeSort(a, left, middle);
	mergeSort(a, middle + 1, right);
	merge(a, left, middle, middle + 1, right);
}

int main() {
	//Считываем входной массив, запускаем сортировку слиянием, в
	//которой подсчитываем количество t - существенных инверсий swaps.
	int i, n;
	scanf("%d %d", &n, &t);
	for (swaps = i = 0; i < n; i++) scanf("%d", &m[i]);
	mergeSort(m, 0, n - 1);
	printf("%d\n", swaps);
	return 0;
}
