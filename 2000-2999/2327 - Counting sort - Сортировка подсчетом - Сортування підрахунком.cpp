#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int i, j, n, v, m[100001];
	//В m[i] подсчитываем сколько раз встретилось число i среди заданных.
	scanf("%d", &n);
	memset(m, 0, sizeof m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		m[v]++;
	}
	//Выводим полученный массив. Число i выводим m[i]  раз.
	for (i = 0; i < 100001; i++)
		for (j = 0; j < m[i]; j++) printf("%d ", i);
	printf("\n");
	return 0;
}
