#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
int c, i, n, k, u, v;

int main() {
	scanf("%d %d", &n, &k);
	g.resize(n + 1);

	//Для каждой строки читаем код операции в переменную c.
	while (k--)
	{
		scanf("%d", &c);

		//Если это операция AddEdge, то добавляем неориентированное ребро(u, v) в граф.
		if (c == 1)
		{
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		else //Иначе выводим список вершин, смежных с вершиной u.Для этого следует вывести все содержимое динамического массива g[u].
		{
			scanf("%d", &u);
			if (g[u].size())
			{
				printf("%d", g[u][0]);
				for (i = 1; i < g[u].size(); i++) printf(" %d", g[u][i]);
			}
			//Выводим символ перехода на новую строку.Если g[u] пусто, то фактически будет выведена пустая строка.
			printf("\n");
		}
	}
	return 0;
}
