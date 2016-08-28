#include <iostream>
#include <string.h>

using namespace std;

#define MAX 1001
int i, j, n, mind, maxd, Error, used[MAX], g[MAX][MAX];

//Поиск в глубину из вершины v. Красим вершину v цветом Color. Проверяем,
//является ли граф двудольным, если разрешено проходить лишь по ребрам,
//веса которых больше Value. То есть можно ли разбить граф на две доли так,
//чтобы все ребра с весом больше Value соединяли вершины из разных долей.
void dfs(int v, int Color, int Value)
{
	if (Error) return;
	used[v] = Color;
	for (int i = 1; i <= n; i++)
		if (g[v][i] > Value)
			if (!used[i]) dfs(i, 3 - Color, Value);
			else if (used[i] == used[v]) Error = 1;
}

//Функция CanDivide возвращает 1, если возможно разделить сад так, чтобы по тропинкам
//длины Value не ходили садовники.Поиск в глубину запускаем как на несвязном графе,
//так как реально он будет вестись только по ребрам, вес которых больше Value.
int CanDivide(int Value)
{
	memset(used, 0, sizeof used);
	Error = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i]) dfs(i, 1, Value);
		if (Error) return 0;
	}
	return 1;
}

int main() {
	//Читаем входные данные. Ищем длину минимального mind и максимального maxd ребра.
	scanf("%d", &n);
	mind = 2e9; maxd = 0;
	memset(g, 0, sizeof g);
	for (i = 1; i < n; i++) {
		for (j = i + 1; j <= n; j++)
		{
			scanf("%d", &g[i][j]);
			g[j][i] = g[i][j];
			if (g[i][j] > maxd) maxd = g[i][j];
			if (g[i][j] < mind) mind = g[i][j];
		}
	}
	//Если имеется два дерева (n = 2), то ответ 0. Этот случай следует обработать отдельно.
	if (n == 2) maxd = 0;
	else //Иначе запускаем бинарный поиск на промежутке [mind, maxd].
		while (mind < maxd)
		{
			int Middle = (mind + maxd) / 2;
			if (CanDivide(Middle)) maxd = Middle;
			else mind = Middle + 1;
		}

	printf("%d\n", maxd);
	return 0;
}
