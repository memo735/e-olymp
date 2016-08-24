#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001
#define LOGMAX 17

int i, n, q, u, v, a[MAX], mas[MAX][LOGMAX];

//Заполняем массив m так, чтобы mas[i][j] = max(bi, bi + 1, …, bi + 2 ^ j - 1).
void Build_RMQ_Array(int *b)
{
	int i, j;
	for (i = 1; i <= n; i++) mas[i][0] = b[i];
	for (j = 1; 1 << j <= n; j++)
		for (i = 1; i + (1 << j) - 1 <= n; i++)
			mas[i][j] = max(mas[i][j - 1], mas[i + (1 << (j - 1))][j - 1]);
}

//Выполняем запрос RMQ(i, j), возвращающий максимальный элемент в подмассиве a[i…j].
int RangeMaxQuery(int i, int j)
{
	int temp, k = 0;
	if (i > j) temp = i, i = j, j = temp;
	while (1 << (k + 1) <= j - i + 1) k++;
	return max(mas[i][k], mas[j - (1 << k) + 1][k]);
}

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	//Совершаем препроцессинг.По массиву a строим массив mas.
	Build_RMQ_Array(a);
	
	//Последовательно выполняем запросы и выводим их результаты.
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &u, &v);
		printf("%d\n", RangeMaxQuery(u, v));
	}
	return 0;
}
