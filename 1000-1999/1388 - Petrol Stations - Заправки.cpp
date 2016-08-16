#include <iostream>
#include <string.h>

#define MAX 110
#define INF 0x3F3F3F3F

int a, b, n, m, j, w, Min, mas[MAX][MAX], used[MAX], d[MAX], cost[MAX];

//Релаксация ребра(i, j) с весом mas[i][j].
void Relax(int i, int j)
{
	if (d[i] + mas[i][j] < d[j]) d[j] = d[i] + mas[i][j];
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);

	//Строим граф стоимостей переездов.
	memset(mas, 0x3F, sizeof mas);
	memset(used, 0, sizeof used);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		mas[a][b] = cost[a];
		mas[b][a] = cost[b];
	}
	//Инициализируем кратчайшие расстояния из первой вершины до остальных.
	memset(d, 0x3F, sizeof d);
	d[1] = 0;

	//Запускаем цикл алгоритма Дейкстры. На каждой итерации находим вершину w с минимальным расстоянием
	//min до истока.Если окажется w = -1, то искомого пути не существует и мы выходим из цикла.
	for (int i = 1; i < n; i++)
	{
		Min = INF; w = -1;
		for (j = 1; j <= n; j++)
			if (!used[j] && d[j] < Min)
			{
				Min = d[j];
				w = j;
			}
		if (w < 0) break;
		for (j = 1; j <= n; j++)
			if (!used[j]) Relax(w, j);
		used[w] = 1;
	}
	//Выводим ответ в зависимости от значения dist[n]. Если оно равно бесконечности, то
	//пути до требуемой вершины не существует.Иначе выводим искомое кратчайшее расстояние.
	if (d[n] == INF) printf("-1\n");
	else printf("%d\n", d[n]);
	return 0;
}
