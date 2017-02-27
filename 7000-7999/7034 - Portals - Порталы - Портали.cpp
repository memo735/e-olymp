#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1001
int cnt, cost[MAX], used[MAX], mn[MAX];
vector<vector<int> > g;

//Поиск в глубину из вершины v, принадлежащей cnt - ой компоненте связности. Проходим
//по всем вершинам компоненты и ищем в mn[cnt] наименьшую стоимость постройки портала.
void dfs(int v)
{
	used[v] = 1;
	mn[cnt] = min(mn[cnt], cost[v]);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to]) dfs(to);
	}
}

int main() {
	int i, n, m, u, v, res;
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for (i = 1; i <= n; i++) scanf("%d", &cost[i]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//Для каждой компоненты связности cnt запускаем поиск в глубину. Ищем вершину с
	//наименьшей стоимостью постройки портала, найденную стоимость заносим в mn[cnt].
	for (i = 0; i < MAX; i++) mn[i] = 1e9;
	for (cnt = 0, i = 1; i <= n; i++)
		if (!used[i]) dfs(i), cnt++;

	//Всего граф содержит cnt компонент связности. В переменной temp ищем вершину с
	//наименьшей стоимостью построения портала – минимум среди всех значений mn[0], …, mn[cnt – 1].
	//В переменной res найдем сумму этих минимумов.
	int temp = 1e9;
	for (res = i = 0; i < cnt; i++)
	{
		if (mn[i] < temp) temp = mn[i];
		res += mn[i];
	}
	//Пусть, например, минимум temp достигается в j - ой компоненте связности (temp = mn[j]).
	//Тогда общая сумма построения порталов res для всех новых переходов составит
	//(mn[j] + mn[0]) + … + (mn[j] + mn[j – 1]) + (mn[j] + mn[j + 1]) + … + (mn[j] + mn[cnt – 1]) =
	//= mn[j] * (cnt – 1) + mn[0] + … + mn[j – 1] + mn[j + 1] + … + mn[cnt – 1] =
	//= temp * (cnt – 2) + mn[0] + … + mn[cnt – 1]
	res += temp * (cnt - 2);
	printf("%d\n", res);
	return 0;
}
