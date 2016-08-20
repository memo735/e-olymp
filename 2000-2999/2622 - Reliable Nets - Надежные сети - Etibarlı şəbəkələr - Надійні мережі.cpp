#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF 0x3F3F3F3F
#define MaxV 20

int i, n, m, cs, res, vaxt, TotLen, IsBridge;
int used[MaxV], d[MaxV], up[MaxV], best[1 << MaxV], graph[MaxV][MaxV];

//Список ребер входного графа храним в явном виде в массиве структур E.
struct Edge
{
	int u, v, dist;
} E[MaxV];

//Поиск в глубину dfs проверяет наличие мостов в графе. Если мост
//присутствует, то переменная IsBridge устанавливается равной 1.
void dfs(int v, int p = -1)
{
	if (IsBridge) return;
	used[v] = 1;
	d[v] = up[v] = vaxt++;
	for (int to = 1; to <= n; to++)
	{
		if (to == p || !graph[v][to]) continue;
		if (used[to]) up[v] = min(up[v], d[to]);
		else
		{
			dfs(to, v);
			up[v] = min(up[v], up[to]);
			if (up[to] > d[v]) IsBridge = 1;
		}
	}
}

//Функция IsBiconnected возвращает 1, если граф реберно
//двусвязный. Для этого в графе должны отсутствовать мосты.
int IsBiconnected()
{
	vaxt = 1; IsBridge = 0;
	memset(used, 0, sizeof used);
	memset(d, 0, sizeof d);
	memset(up, 0, sizeof used);
	for (int i = 1; i <= n; i++)
	{
		if (!used[i]) dfs(i);
		if (IsBridge) break;
	}
	return !IsBridge;
}

//Вычисляем минимальную стоимость сети, которую можно образовать из ребер, задаваемых
//маской mask. Длина всех ребер подграфа, задаваемого маской mask, равна CurLen.
int go(int mask, int CurLen)
{
	//Если значение best[mask] уже вычислено (оно не равно INF), то возвращаем его.
	//Если текущий подграф не является двусвязным, то останавливаем процесс перебора,
	//значение best[mask] полагаем равным INF – 1, что считается уже вычисленным.
	if (best[mask] != INF) return best[mask];
	if (!IsBiconnected()) return best[mask] = INF - 1;
	best[mask] = CurLen;

	//Перебираем ребра, входящие в подграф. Удаляем из графа лишь одно i-ое ребро и
	//рекурсивно решаем задачу для подграфа, который задается маской mask XOR 2^i.
	//Длина ребер этого графа будет равна CurLen – E[i].dist.
	for (int i = 0; i < m; i++)
	{
		if (mask & (1 << i))
		{
			graph[E[i].u][E[i].v] = graph[E[i].v][E[i].u] = 0;
			int opt = go(mask ^ (1 << i), CurLen - E[i].dist);
			if (opt < best[mask]) best[mask] = opt;
			graph[E[i].u][E[i].v] = graph[E[i].v][E[i].u] = 1;
		}
	}
	return best[mask];
}

int main() {
	//Читаем ребра графа и запоминаем их в массиве E. Строим матрицу смежности graph.
	//Дины ребер хранятся только в массиве Е.Вычисляем длину всех ребер в переменной TotLen.
	while (scanf("%d %d", &n, &m), n + m)
	{
		memset(best, 0x3F, sizeof best);
		memset(graph, 0, sizeof graph);
		res = INF;
		for (TotLen = i = 0; i < m; i++)
		{
			scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].dist);
			graph[E[i].u][E[i].v] = graph[E[i].v][E[i].u] = E[i].dist;
			TotLen += E[i].dist;
		}
		//Находим ответ и выводим его в зависимости от того, существует ли искомая надежная сеть.
		//Графу, который содержит все ребра, соответствует маска 2^m – 1, состоящая из m единиц.
		res = go((1 << m) - 1, TotLen);
		if (res >= INF - 1) printf("There is no reliable net possible for test case %d.\n", ++cs);
		else printf("The minimal cost for test case %d is %d.\n", ++cs, res);
	}
	return 0;
}
