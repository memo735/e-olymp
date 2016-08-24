#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001
#define LOGMAX 18

vector<int> g[MAX];
int i, n, l, q, x, y, lca, Chip, Deil, Price, timer;
int d[MAX], f[MAX], dist[MAX], up[MAX][LOGMAX];

//Запускаем поиск в глубину из вершины v. Предком v является p.
//Расстояние до вершины v из столицы(вершины номер 1) равно len.
//Его сохраняем в ячейке dist[v]. Вычисляем метки d и f.
void dfs(int v, int p = 1, int len = 0)
{
	int i, to;
	d[v] = timer++;
	up[v][0] = p; dist[v] = len;
	for (i = 1; i <= l; i++) up[v][i] = up[up[v][i - 1]][i - 1];
	//Просматриваем, куда можно пойти из вершины v.Идем по ребру дерева(v, to).
	for (i = 0; i < g[v].size(); i++)
	{
		to = g[v][i];
		if (to != p) dfs(to, v, len + 1);
	}
	f[v] = timer++;
}

//Функция Parent возвращает истину, если a является предком b.
int Parent(int a, int b)
{
	return d[a] <= d[b] && f[a] >= f[b];
}

//Вычисление ближайшего общего предка методом двоичного подъема, используя массив up.
int LCA(int a, int b)
{
	if (Parent(a, b)) return a;
	if (Parent(b, a)) return b;
	for (int i = l; i >= 0; i--)
		if (!Parent(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

int main() {
	//Читаем входные данные. Вычисляем l = log2(n). Строим неориентированный
	//граф, который по условию задачи является деревом.
	scanf("%d %d", &n, &Price);
	l = 1;
	while (1 << l <= n)  l++;
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	//Запускаем поиск в глубину из столицы, в которой находится кинотеатр.
	dfs(1);
	//Обрабатываем q запрсов.
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &x, &y);
		lca = LCA(x, y);
		//Чип до встречи проедет dist[x] – dist[lca] км, а Дейл dist[y] – dist[lca] км.
		//Вместе на машине они проедут в точности dist[lca] км.Вычисляем и выводим ответ.
		Chip = dist[x] - dist[lca];
		Deil = dist[y] - dist[lca];
		printf("%.5lf %.5lf\n", (Chip + dist[lca] / 2.0) * Price, (Deil + dist[lca] / 2.0) * Price);
	}
	return 0;
}
