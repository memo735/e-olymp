#include <iostream>
#include <vector>

using namespace std;

int test, n, m, a, b, i, j;
vector <vector<int> > g;
vector <int> used, res;
bool result = false;

void dfs(int v, int prev)
{
	used[v] = prev;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (used[g[v][i]] > 0 && !result)
		{
			result = true;
			int ii = v;
			while (ii != used[g[v][i]])
			{
				res.push_back(ii);
				ii = used[ii];
			}
			break;
		}
		if (used[g[v][i]] == 0) dfs(g[v][i], v);
	}
	used[v] = -1;
}

int main()
{
	cin >> n >> m;
	g.resize(n + 1);
	used.resize(n + 1);
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) if (used[i] == 0) dfs(i, 1000000);
	if (result)
	{
		cout << "YES\n";
		for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
	}
	else cout << "NO\n";
	return 0;
}
