#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > g;
int diameter, i, n, u, v, tests;

int dfs(int v, int prev = -1)
{
	int h1 = 0, h2 = 0; // highest and second highest height
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to != prev)
		{
			int h = dfs(to, v) + 1;
			if (h > h1) h2 = h1, h1 = h;
			else if (h > h2) h2 = h;
		}
		diameter = max(diameter, h1 + h2);
	}
	return h1;
}

int main()
{
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		g.clear();
		g.resize(n + 1);
		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		diameter = 0;
		dfs(0);
		printf("%d\n", (diameter + 1) / 2);
	}
	return 0;
}
