#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<int> used, top;
int a, b, i, n, m, Error;

void dfs(int i)
{
	used[i] = 1;
	for (int j = 0; j < graph[i].size(); j++)
	{
		int to = graph[i][j];

		//Если ориентированное ребро (i, to) ведет в серую вершину, то в графе присутствует цикл.
		if (used[to] == 1) Error = 1;

		//Если вершина to еще не просмотрена, то рекурсивно запускаем из нее поиск в глубину.
		if (!used[to]) dfs(graph[i][j]);
	}
	used[i] = 2;
	top.push_back(i);
}

int main() {
	//Читаем входные данные. Строим список смежности графа.
	scanf("%d %d", &n, &m);
	graph.resize(n + 1); used.resize(n + 1);
	for (i = 0; i < n; i++) scanf("%d %d", &a, &b), graph[a].push_back(b);

	//Совершаем обход в глубину вершин графа.
	for (i = 1; i <= n; i++) if (!used[i]) dfs(i);

	//Если в графе присутствует цикл (при обходе в глубину установлено Error = 1), то выводим - 1.
	if (Error) printf("-1\n");
	else
	{
		//Выводим вершины графа в порядке, обратном тому, в котором они заносились в массив top.
		for (i = n - 1; i > 0; i--) printf("%d ", top[i]);
		printf("%d\n", top[0]);
	}
	return 0;
}
