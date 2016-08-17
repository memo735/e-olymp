#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> used, d, f;
int a, b, i, n, m, root, vaxt;

//Запускаем процедуру поиска в глубину dfs.Расставляем метки d[v] и f[v].
void dfs(int v)
{
	used[v] = 1; d[v] = vaxt++;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to]) dfs(to);
	}
	f[v] = vaxt++;
}

//Функция is_Parent возвращает 1, если a является предком b, и 0 иначе.
//Проверяем выполнение двух неравенств d[a] < d[b] и f[b] < f[a].
int is_Parent(int a, int b) { return d[a] < d[b] && f[b] < f[a]; }

int main() {
	//Читаем входной граф. Если вершина a является родителем вершины i, то
	//добавим в граф ориентированное ребро(a, i) (для экономии памяти можно
	//воспользоваться ориентированным графом). Вершины графа нумеруются числами
	//от 1 до n. Если a = 0, то вершина i является корнем, в этом случае никакого
	//ребра добавлять не надо.В переменной root ищем номер вершины – корня дерева.
	scanf("%d", &n);
	g.resize(n + 1); used.resize(n + 1);
	d.resize(n + 1); f.resize(n + 1);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (!a) root = i;
		else g[a].push_back(i);
	}
	dfs(root);

	//Читаем запросы и выводим ответ на каждый из них за константное время.
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", is_Parent(a, b));
	}
	return 0;
}
