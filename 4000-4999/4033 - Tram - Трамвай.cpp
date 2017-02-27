#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define INF 0x3F3F3F3F
vector<int> dist;
vector<vector<pair<int, int> > > g;
int n;

//Поиск в ширину из вершины start. Положим кратчайшее расстояние от стартовой
//вершины до всех остальных равными INF.Расстояние от start до start равно 0.
void bfs(int start)
{
	dist = vector<int>(n + 1, INF);
	dist[start] = 0;
	deque<int> q;
	q.push_back(start);
	while (!q.empty())
	{
		int v = q.front(); q.pop_front();
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i].first, w = g[v][i].second;
			//Если ребро(v, to) релаксирует, то пересчитываем кратчайшее расстояние dist[to].
			if (dist[to] > dist[v] + w)
			{
				dist[to] = dist[v] + w;
				//В зависимости от веса релаксируемого ребра заносим вершину to в конец или в начало очереди.
				if (w == 1) q.push_back(to);
				else q.push_front(to);
			}
		}
	}
}

int main() {
	int a, b, i, j, k, to;
	scanf("%d %d %d", &n, &a, &b);
	g.resize(n + 1);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (j = 0; j < k; j++)
		{
			scanf("%d", &to);
			//В i - ой строке после числа ki стоит номер перекрестка, на который указывает
			//переключатель. Вес этого ребра равен 0. Веса всех остальных исходящих ребер равны 1.
			int w = (j == 0) ? 0 : 1;
			g[i].push_back(make_pair(to, w));
		}
	}
	bfs(a);
	if (dist[b] == INF) printf("-1\n");
	else printf("%d\n", dist[b]);
	return 0;
}
