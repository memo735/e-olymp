#include <iostream>
#include <string.h>

using namespace std;

#define MAX 51
int res, a, b, d, n, k, i, m[MAX][MAX], used[MAX];

//Запускаем поиск в глубину из вершины v.
//При этом известно, что длина пути от a до v уже равна depth.

void dfs(int v, int depth)
{
	if (depth > d) return;

	//Если мы пришли в вершину b, то найден еще один маршрут.
	//Увеличиваем количество путей res на единицу и возвращаемся назад.
	if (v == b)
	{
		res++;
		return;
	}
	used[v] = 1;

	//Ищем вершину i, в которую можно попасть из v.
	for (int i = 1; i <= n; i++)
		if (m[v][i] && !used[i]) dfs(i, depth + 1);

	//Поскольку происходит перебор вершин с возвратом, то следует установить вершину v как непройденную.
	used[v] = 0;
}

//Ориентированный граф читаем в матрицу смежности m.
int main() {
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &d);
	memset(m, 0, sizeof m);
	memset(used, 0, sizeof used);
	for (res = i = 0; i < k; i++)
	{
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		m[a1][a2] = 1;
	}
	dfs(a, 0);
	printf("%d\n", res);
	return 0;
}
