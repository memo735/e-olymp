#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int mas[MAX][17];
int i, n, q, u, v, a[MAX], b[MAX];

//По массиву b строим массив mas, для которого mas[i][j] = min(bi, bi + 1, …, bi + 2 ^ j).
void Build_RMQ_Array(int *b)
{
	int i, j;
	for (i = 1; i <= n; i++) mas[i][0] = b[i];
	for (j = 1; 1 << j <= n; j++)
		for (i = 1; i + (1 << j) - 1 <= n; i++)
			mas[i][j] = min(mas[i][j - 1], mas[i + (1 << (j - 1))][j - 1]);
}

//Функция RMQ возвращает минимум на отрезке(bi, bi + 1, …, bj) за O(1).
int RMQ(int i, int j)
{
	int k = 0;
	while (1 << (k + 1) <= j - i + 1) k++;
	return min(mas[i][k], mas[j - (1 << k) + 1][k]);
}

int main() {
	//Читаем входные данные.Заносим перестановку в массив b.
	scanf("%d %d", &n, &q);
	for (i = 1; i <= n; i++) scanf("%d", &b[i]);
	//Пересчитаем данные массива a.
	for (i = 1; i <= n; i++) a[b[i]] = i;
	//Произведем предобработку данных для запросов RMQ.
	Build_RMQ_Array(a);
	//Читаем запрос(u, v) и выводим на него ответ.
	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &u, &v);
		printf("%d\n", RMQ(u, v));
	}
	return 0;
}
