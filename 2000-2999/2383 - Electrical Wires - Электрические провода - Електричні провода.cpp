#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int i, j, n, num, val, Edges, Vertex, m[51][51], used[51];
vector<int> gridConnections;

//Поиск в глубину используется для выделения компонент связности графа. В глобальной
//переменной Vertex подсчитываем количество вершин, входящих в текущую компоненту связности.
void dfs(int v)
{
	int i;
	used[v] = 1; Vertex++;
	for (i = 0; i < n; i++) if (m[v][i] && !used[i]) dfs(i);
}

//Функция maxNewWires возвращает максимальное количество проводов, которое можно добавить в электрическую схему.
int maxNewWires()
{
	int i, res = 0, LeftVertex = n, MaxConnComp = 0;
	memset(used, 0, sizeof used);

	//Поскольку по условию задачи в каждую компоненту связности может входить максимум
	//один внешний узел электросети, запускаем поиск в глубину из каждого такого узла.
	for (i = 0; i < gridConnections.size(); i++)
	{
		Vertex = 0;
		dfs(gridConnections[i]);

		//В компоненту связности, содержащую вершину gridConnections[i], входит Vertex вершин.
		//Через Vertex вершин можно провести Vertex * (Vertex – 1) / 2 проводов. MaxConnComp
		//содержит количество вершин в наибольшей компоненте связности.
		res += Vertex * (Vertex - 1) / 2;
		LeftVertex -= Vertex;
		MaxConnComp = max(MaxConnComp, Vertex);
	}
	//Осталось LeftVertex вершин, которые даже косвенно не связаны с внешними узлами электросети.
	//Соединяем проводами все возможные пары этих(LeftVertex * (LeftVertex – 1) / 2 новых проводов),
	//а также присоединяем каждую из них ко всем вершинам из  наибольшей компоненты связности
	//(MaxConnComp * LeftVertex новых проводов).
	res += LeftVertex * (LeftVertex - 1) / 2 + MaxConnComp * LeftVertex;
	return res - Edges;
}

int main() {
	//Читаем входные данные.Подсчитываем количество ребер в графе Edges.
	while (scanf("%d", &n) == 1)
	{
		for (Edges = i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
			{
				scanf("%1d", &m[i][j]);
				if (m[i][j]) Edges++;
			}
		}
		scanf("%d", &num); gridConnections.clear();
		for (i = 0; i < num; i++) scanf("%d", &val), gridConnections.push_back(val);

		//Поскольку граф неориентированный, то каждое ребро будет посчитано дважды.
		Edges /= 2;
		printf("%d\n", maxNewWires());
	}
	return 0;
}
