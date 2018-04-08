#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<int> used;
set<int>::iterator iter;
map<int, vector<int> > g;

//Поиск в глубину из вершины v.
void dfs(int v)
{
	//Отмечаем вершину v пройденной.
	used.insert(v);
	//Перебираем вершины, смежные с v.
	for (int to : g[v])
	{
		//В графе имеется ребро(v, to).
		//Если вершина to еще не пройдена, то запускаем поиск в глубину из to.
		if (used.find(to) == used.end()) dfs(to);
	}
}

int main() {
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
	}
	dfs(1);
	printf("%d\n", used.size());
	for (iter = used.begin(); iter != used.end(); ++iter) printf("%d\n", *iter);
	return 0;
}
