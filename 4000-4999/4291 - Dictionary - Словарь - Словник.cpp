#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 26

int i, j, n, temp, flag, g[MAX][MAX], used[MAX];
char s1[MAX], s2[MAX];

//Поиск в глубину из вершины v. Цикл в ориентированном графе существует только если
//в процессе поиска существует ребро, ведущее в серую вершину (вершина считается серой,
//если used[i] = 1, и черной при used[i] = 2). При обнаружении цикла установим flag = 1.
void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < MAX; i++)
	{
		if (g[v][i])
		{
			if (used[i] == 1) flag = 1;
			else if (!used[i]) dfs(i);
		}
	}
	used[v] = 2;
}

int main() {
	//Читаем входные данные. Строим граф зависимостей.
	while (scanf("%d\n", &n), n)
	{
		memset(g, 0, sizeof g);
		memset(used, 0, sizeof used);
		flag = 0;
		gets(s1);
		for (j = 0; j < n - 1; j++)
		{
			gets(s2);
			//s1 и s2 – две последовательно стоящие строки во входных данных.
			temp = min(strlen(s1), strlen(s2));
			for (i = 0; i < temp; i++) {
				if (s1[i] != s2[i])
				{
					g[s1[i] - 'a'][s2[i] - 'a'] = 1;
					break;
				}
			}
			//Если s2 является префиксом s1 (при этом s1 ≠ s2), то это не лексикографический порядок.
			if (i == temp && strlen(s1) > strlen(s2)) flag = 1;
			strcpy(s1, s2);
		}
		//Запускаем поиск в глубину на ориентированном графе.
		for (i = 0; i < MAX; i++) if (!used[i]) dfs(i);
		//В зависимости от значения flag выводим ответ.
		puts(flag ? "no" : "yes");
	}
	return 0;
}
