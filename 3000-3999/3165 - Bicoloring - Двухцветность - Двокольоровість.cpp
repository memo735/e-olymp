#include <iostream>
#include <vector>

using namespace std;

int test, n, m, a, b, i, j;
vector <vector<int> > g;
vector <int> used;
bool result;

void dfs(int v, int color)
{
	used[v] = color;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (used[g[v][i]] == color)
		{
			result = false;
			break;
		}
		if (!used[g[v][i]]) dfs(g[v][i], 3 - color);
	}
}

int main()
{
	n = 1;
	while (n)
	{
		cin >> n;
		if (n)
		{
			cin >> m;
			g.clear(); g.resize(n);
			used.clear(); used.resize(n);
			result = true;
			for (i = 0; i < m; i++)
			{
				cin >> a >> b;
				g[a - 1].push_back(b - 1);
				g[b - 1].push_back(a - 1);
			}
			dfs(0, 1);
			cout << (result ? "BICOLOURABLE.\n" : "NOT BICOLOURABLE.\n");
		}
	}
	return 0;
}
