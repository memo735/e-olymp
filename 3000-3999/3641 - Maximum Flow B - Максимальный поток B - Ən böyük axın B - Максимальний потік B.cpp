#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 10001
int i, k, n, u, v, res, Left, Right, a[MAX], b[MAX], used[2 * MAX];
vector<vector<int> > g;

//Поиск в глубину из вершины v. Проходим по всем вершинам одной компоненты связности.
//Для каждой вершины v левой доли к переменной Left прибавляем значение пропускной
//способности ребра, входящего в v. Для каждой вершины v правой доли к переменной
//Right прибавляем значение пропускной способности ребра, исходящего из v.
void dfs(int v)
{
	if (v > n) Right += b[v - n]; else Left += a[v];
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to]) dfs(to);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	g.assign(2 * n + 1, vector<int>());
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= n; i++) scanf("%d", &b[i]);

	//Строим граф, ребра которого неориентированные и имеют веса бесконечность. Вершины левой
	//доли нумеруем числами от 1 до n. Вершины правой доли нумеруем числами от n + 1 до 2n.
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &u, &v);
		g[u].push_back(v + n); g[v + n].push_back(u);
	}
	//Запускаем поиск в глубину на графе. Выделяем его компоненты связности. Если в одну компоненту
	//входят трубы пропускной способности Left, а выходят с суммарной пропускной способностью Right,
	//то через эту компоненту можно пропустить поток величины min(Left, Right). Результирующую
	//величину максимального потока подсчитываем в переменной res.
	res = 0;
	memset(used, 0, sizeof used);
	for (i = 1; i <= n; i++) {
		if (!used[i])
		{
			Left = Right = 0;
			dfs(i);
			res += min(Left, Right);
		}
	}
	printf("%d\n", res);
	return 0;
}
