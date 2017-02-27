#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > > g;
vector<int> depth, res;

//Максимальное расстояние от вершины v до листа в поддереве с корнем v вычисляем в depth[v] при помощи функции dfs1.
void dfs1(int v, int prev = -1)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int w = g[v][i].second;
		if (to != prev)
		{
			dfs1(to, v);
			depth[v] = max(depth[v], depth[to] + w);
		}
	}
}

//Второй обход в глубину для каждой вершины v находит наибольшее возможное расстояние до любой из вершин дерева res[v].
void dfs2(int v, int prev = -1, int h = 0)
{
	res[v] = max(h, depth[v]);
	//Вычисляем наибольшее h1 и второе наибольшее h2 расстояние от v до листа в поддереве с корнем в v.
	int h1 = 0, h2 = 0;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first, w = g[v][i].second;
		if (to != prev)
		{
			int h = depth[to] + w;
			if (h > h1) h2 = h1, h1 = h;
			else
				if (h > h2) h2 = h;
		}
	}
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int w = g[v][i].second;
		if (to == prev) continue;
		if (h1 == depth[to] + w) dfs2(to, v, max(h, h2) + w);
		else dfs2(to, v, max(h, h1) + w);
	}
}

int main() {
	int i, n, u, v, dist;
	scanf("%d", &n);
	g.resize(n + 1);
	depth.resize(n + 1); res.resize(n + 1);
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &u, &v, &dist);
		g[u].push_back(make_pair(v, dist));
		g[v].push_back(make_pair(u, dist));
	}
	dfs1(1);
	dfs2(1);
	for (i = 1; i <= n; i++) printf("%d\n", res[i]);
	return 0;
}
