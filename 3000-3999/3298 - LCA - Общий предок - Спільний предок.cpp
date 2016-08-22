#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define MAX  10001

vector<int> g[MAX], gr[MAX];
int i, j, n, m, u, v, res, used[MAX], gSize[MAX], grSize[MAX];

//Запускаем сначала поиск в ширину из вершины v по ребрам транспонированного
//графа. Все пройденные вершины сохраняются в массиве(очереди) Q.
void bfs(int v)
{
	int Q[MAX], qh = 0, qt = 1;
	Q[0] = v; used[v] = 1;
	while (qh < qt)
	{
		int u = Q[qh++];
		for (int i = 0; i < grSize[u]; i++)
		{
			int to = gr[u][i];
			if (!used[to])
			{
				used[to] = 1;
				Q[qt++] = to;
			}
		}
	}
	//Запускаем поиск в ширину из вершин, хранящихся в очереди Q, по ребрам исходного графа.
	qh = 0;
	while (qh < qt)
	{
		int u = Q[qh++];
		for (int i = 0; i < gSize[u]; i++)
		{
			int to = g[u][i];
			if (!used[to])
			{
				used[to] = 1;
				Q[qt++] = to;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	memset(gSize, 0, sizeof gSize);
	memset(grSize, 0, sizeof grSize);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		g[u].push_back(v); gr[v].push_back(u);
		gSize[u]++; grSize[v]++;
	}
	//Последовательно запускаем поиск в ширину из вершин 1, 2, …, n. Для каждой вершины i
	//после вызова bfs(i) подсчитываем при помощи массива used количество вершин j таких,
	//что для (i, j) имеется общий предок (оно равно числу таких j, для которых used[j] = 1).
	for (i = 1; i <= n; i++)
	{
		memset(used, 0, sizeof used);
		bfs(i);
		for (j = 1; j <= n; j++) if (used[j]) res++;
	}
	printf("%d\n", res);
	return 0;
}
