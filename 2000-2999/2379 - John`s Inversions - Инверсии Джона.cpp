#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int a, b, i, n, m[100001];
long swaps;
vector<pair<int, int>> v;

//Слияние a[bleft..bright] и a[cleft..cright] в a[bleft..cright]. Для этого
//используется дополнительный массив res. Сначала копируем a[bleft..bright]
//в res[0 ..len – 1], после чего сливаем res[0 ..len – 1] и a[cleft..cright].
void merge(int *a, int bleft, int bright, int cleft, int cright)
{
	int len = bright - bleft + 1, resCur = 0;
	int *res = new int[len];
	memcpy(res, a + bleft, len * sizeof(int));
	while (resCur < len && cleft <= cright)
	{
		if (res[resCur] <= a[cleft]) a[bleft++] = res[resCur++];
		else a[bleft++] = a[cleft++], swaps += len - resCur;
	}
	while (resCur < len) a[bleft++] = res[resCur++];
	delete[] res;
}

//Сортировка слиянием массива a[left..right].
void mergeSort(int *a, int left, int right)
{
	if (left >= right) return;
	int middle = (left + right) / 2;
	mergeSort(a, left, middle);
	mergeSort(a, middle + 1, right);
	merge(a, left, middle, middle + 1, right);
}

int main() {
	//Читаем числа на картах.Сортируем карты по возрастанию красных чисел.
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	//Синие числа на картах занесем в массив m.
	for (i = 0; i < n; i++) m[i] = v[i].second;

	//Вычисляем и выводим количество инверсий в массиве m.
	swaps = 0;
	mergeSort(m, 0, n - 1);
	printf("%ld\n", swaps);
	return 0;
}
