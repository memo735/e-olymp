#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > g;
int a, b, i, n, ans, ans1;

//Функция dfs возвращает значение, на единицу большее количества бандитов,
//являющихся для v-го подчиненными. В переменной p хранится предок вершины v.
int dfs(int v, int p = -1)
{
	int i, res = 1;
	for (i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p) continue;
		res += dfs(to, v);
	}
	if (ans == 0 && res >= n / 2 + 1) ans = v;
	if (res * 2 == n) ans1 = v;
	return res;
}

int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans1 = ans = 0;
	dfs(1);
	if (ans1) printf("%d %d\n", min(ans, ans1), max(ans, ans1));
	else printf("%d\n", ans);
	return 0;
}
