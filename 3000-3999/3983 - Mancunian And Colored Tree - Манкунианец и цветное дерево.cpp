#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> col, res;
vector<vector<int> > g;
vector<stack<int> > s;

void dfs(int v)
{
	int color = col[v];
	if (s[color].empty()) res[v] = -1;
	else res[v] = s[color].top();
	s[color].push(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
	}
	s[color].pop();
}

int main() {
	int i, n, c, val;
	scanf("%d %d", &n, &c);
	g.resize(n + 1);
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &val);
		g[val].push_back(i);
	}
	col.resize(n + 1);
	for (i = 1; i <= n; i++) scanf("%d", &col[i]);
	s.resize(c + 1);
	res.resize(n + 1);
	dfs(1);
	for (i = 1; i <= n; i++) printf("%d ", res[i]);
	printf("\n");
	return 0;
}
