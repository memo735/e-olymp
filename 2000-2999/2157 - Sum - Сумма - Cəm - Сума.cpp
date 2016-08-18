#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000;

vector<vector<pair<int, int>>> g;
int d, i, n, u, v;
long res;

//Поиск в глубину из вершины v. Функция dfs возвращает количество вершин в поддереве
//с корнем v (включая саму вершину v). Подсчет этих вершин происходит в переменной cnt.
//Изначально положим cnt = 1, считая что в поддерево включена сама вершина v.
int dfs(int v, int p = -1)
{
	int cnt = 1, c;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int w = g[v][i].second;

		//Рассмотрим ребро(v, to) с весом w. Вычисляем количество вершин c в поддереве с корнем to. Таким образом
		//в дереве с одной стороны ребра находится c вершин, а с другой n – c вершин. Ребро (v, to) входит в
		//c * (n – c) различных путей. Поэтому вклад этого ребра в сумму длин всех путей составляет c * (n – c) * w.
		if (to != p)
		{
			c = dfs(to, v);
			res = (res + 1L * c * (n - c) * w) % MOD;
			cnt += c;
		}
	}
	return cnt;
}

int main() {
	//Читаем взвешенный граф в список смежности g.
	scanf("%d", &n);
	g.resize(n + 1);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d %d", &u, &v, &d);
		g[u].push_back(make_pair(v, d));
		g[v].push_back(make_pair(u, d));
	}
	dfs(1);
	printf("%ld\n", res);
	return 0;
}
