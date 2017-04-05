#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> used, mt, par;
int i, j, k, n, run, flow;

//Поск в глубину из вершины v.Ищем дополняющий путь.
int dfs(int v)
{
	if (used[v]) return 0;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (mt[to] == -1 || dfs(mt[to]))
		{
			mt[to] = v;
			par[v] = 1;
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		g[i].assign(k, 0);
		for (j = 0; j < k; j++) scanf("%d", &g[i][j]);
	}
	//Ищем максимальное паросочетание в переменной flow.
	//Поиск максимального паросочетания.
	mt.assign(n, -1);
	par.assign(n, -1);
	for (run = 1; run; )
	{
		run = 0; used.assign(n, 0);
		for (i = 0; i < n; i++)
			if (par[i] == -1 && dfs(i)) run = 1;
	}
	for (flow = 0, i = 0; i < n; i++) if (mt[i] != -1) flow++;
	printf("%d\n", n - flow);
	return 0;
}
