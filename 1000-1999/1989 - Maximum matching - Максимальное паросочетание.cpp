#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> used, mt;
int a, b, i, n, m, k, flow;

//Функция dfs ищет дополняющий путь из вершины v поиском в глубину
//и возвращает 1, если такой путь будет найден. В случае нахождения
//увеличивающей цепи производится чередование паросочетания вдоль нее.
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
			return 1;
		}
	}
	return 0;
}

//Поиск максимального паросочетания.
void AugmentingPath()
{
	//Изначально текущее паросочетание пусто.
	mt.assign(m + 1, -1);

	//Запускаем поиск дополняющего пути из каждой вершины левой доли.
	//Предварительно обнуляем массив посещенных вершин used.
	for (int i = 1; i <= n; i++)
	{
		used.assign(n + 1, 0);
		dfs(i);
	}
}

int main() {

	scanf("%d %d %d", &n, &m, &k);
	g.resize(n + 1);
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
	}
	//Ищем и выводим величину максимального паросочетания.
	AugmentingPath();
	for (flow = 0, i = 1; i <= m; i++) if (mt[i] != -1) flow++;
	printf("%d\n", flow);
	//Выводим само максимальное паросочетание.
	for (i = 1; i <= m; i++) if (mt[i] != -1) printf("%d %d\n", mt[i], i);
	return 0;
}
