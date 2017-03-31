#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3F3F3F3F
vector<int> used, dist, mult;

//Ребро графа содержит номер вершины node в которое направлено и свою длину dist. Определим
//оператор сравнения ребер : в очереди с приоритетами они будут располагаться по убыванию длин.
struct edge
{
	int node, dist;
	edge(int node, int dist) : node(node), dist(dist) {}
	bool operator< (const edge a) const { return dist > a.dist; }
};

//Определим список смежности графа g и очередь с приоритетами pq для алгоритма Дейкстры.
vector<vector<edge> > g;
priority_queue<edge> pq;

//Релаксация ребра идущего от v к to длины cost. Если dist[to] = dist[v] + cost,
//то существует как минимум второй путь от начальной вершины к to. Устанавливаем
//mult[to] = 1. В случае релаксации существование более одного пути к v должно
//вести к существованию более одного пути к to, положим mult[to] = mult[v].
void Relax(int v, int to, int cost)
{
	if (dist[to] == dist[v] + cost) mult[to] = 1;
	if (dist[to] > dist[v] + cost)
	{
		dist[to] = dist[v] + cost;
		pq.push(edge(to, dist[to]));
		mult[to] = mult[v];
	}
}

int main() {
	int a, b, i, j, n, m, k, v, w, to, cost, temp;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < k; i++) scanf("%d", &temp);
	g.resize(n + 1);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		g[a].push_back(edge(b, w));
		g[b].push_back(edge(a, w));
	}
	dist.assign(n + 1, INF);
	dist[1] = 0;
	used.assign(n + 1, 0);
	mult.assign(n + 1, 0);
	pq.push(edge(1, 0));
	while (!pq.empty())
	{
		edge e = pq.top(); pq.pop();
		v = e.node;
		//Если извлеченная из очереди вершина фиктивна, то не обрабатываем ее.
		if (e.dist > dist[v]) continue;
		//Перебираем и релаксируем ребра, смежные с вершиной v.
		for (j = 0; j < g[v].size(); j++)
		{
			to = g[v][j].node;
			cost = g[v][j].dist;
			if (!used[to]) Relax(v, to, cost);
		}
	}
	puts(mult[n] == 1 ? "yes" : "no");
	return 0;
}
