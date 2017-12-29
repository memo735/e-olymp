#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > g;
vector<int> used;
map<string, int> m;

bool flag;

//Поиск в глубину из вершины v.
void dfs(int v)
{
	if (flag == 1) return;
	used[v] = 1;
	for (int to : g[v])
	{
		//Ребро(v, to) является текущим рассматриваемым. Если оно ведет 
		//в серую вершину, то найден цикл, устанавливаем flag = 1.
		if (used[to] == 1)
		{
			flag = true;
			return;
		}
		if (used[to] == 0) dfs(to);
	}
	//Вершина v по завершению обработки становится черной.
	used[v] = 2;
}

int main()
{
	int i, n = 0, stat;
	char ch, s1[10000], s2[10000];
	//Поскольку количество карликов не превосходит 104, то количество вершин в графе не более 10000.
	scanf("%d", &stat);
	g.resize(10001); used.resize(10001, 0);
	//В переменной n подсчитываем количество карликов. Обрабатываем stat 
	//утверждений. Для каждого утверждения строим ориентированное ребро.
	for (i = 0; i < stat; i++)
	{
		scanf("%s %c %s", s1, &ch, s2);
		if (m[s1] == 0) m[s1] = ++n;
		if (m[s2] == 0) m[s2] = ++n;
		int from = m[s1], to = m[s2];
		ch == '<' ? g[from].push_back(to) : g[to].push_back(from);
	}
	//Запускам поиск в глубину на ориентированном графе. flag = 0 означает что в графе нет циклов.
	flag = false;
	for (i = 1; i <= n; i++)
	{
		if (!used[i]) dfs(i);
		if (flag == 1) break;
	}
	//В зависимости от значения переменной flag выводм ответ.
	printf(flag == 1 ? "impossible\n" : "possible\n");
	return 0;
}
