#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 101
#define INF 0x3F3F3F3F

//Пропускную способность ребер храним в массиве Cap. ptr[i] хранит номер вершины,
//до которой были просмотрены ребра, исходящие из вершины i при поиске в глубину.
//Другими словами ptr[i] хранит указатель на последнее ребро, по которому мы еще
//можем пустить увеличивающий поток.d – массив кратчайших расстояний при поиске в ширину.
long Cap[MAX][MAX];
int a, b, c, n, Edges, ptr[MAX], d[MAX];

//Поиск в глубину из вершины s. В массиве q  моделируется очередь при поиске в ширину.
//Переменная qh содержит указатель на начало очереди, qt – на конец очереди. Заполняем
//ячейки d[i] кратчайшим расстоянием от s до i.Расстояние вычисляется по количеству ребер.
long bfs(int s)
{
	int qh = 0, qt = 0, q[MAX];
	q[qt++] = s;
	memset(d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt)
	{
		int v = q[qh++];
		for (int to = 1; to <= n; to++)
			if (d[to] == -1 && Cap[v][to])
			{
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[n] != -1;
}

//Запускаем поиск дополняющего пути из вершины v, если
//известно, что величина потока от истока до v равна flow.
long dfs(int v, long flow)
{
	if (!flow)  return 0;
	if (v == n)  return flow;
	for (int &to = ptr[v]; to <= n; to++)
	{
		//Двигаемся только по ребрам (v, to) слоистой сети (для которых d[to] = d[v] + 1).
		if (d[to] != d[v] + 1)  continue;

		//Если от истока до v можно пропустить максимальный поток величины flow, то от
		//истока до to можно пропустить максимальный поток величины min(flow, Cap[v][to]).
		int pushed = dfs(to, min(flow, Cap[v][to]));

		//Если существует дополняющий путь, по которому можно увеличить поток от v до
		//стока на величину pushed, то меняем значение пропускной способности ребра(v, to).
		if (pushed)
		{
			Cap[v][to] -= pushed;
			Cap[to][v] += pushed;
			return pushed;
		}
	}
	return 0;
}

//Запускаем алгоритм Диница из вершины s.
long Dinic(int s)
{
	long flow = 0;
	while (true)
	{
		if (!bfs(s))  break;
		for (int i = 1; i <= n; i++) ptr[i] = 1;
		while (long pushed = dfs(s, INF)) flow += pushed;
	}
	return flow;
}

int main() {
	//Читаем входные данные, строим граф.
	scanf("%d %d", &n, &Edges);
	memset(Cap, 0, sizeof Cap);
	while (Edges--) scanf("%d %d %d", &a, &b, &c), Cap[a][b] += c, Cap[b][a] += c;
	printf("%ld\n", Dinic(1));
	return 0;
}
