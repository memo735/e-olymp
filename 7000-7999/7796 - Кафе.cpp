#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3F3F3F3F

class Edge
{
public:
	int vTo, Cap, Flow;
	Edge(int vTo, int Cap, int Flow)
		: vTo(vTo), Cap(Cap), Flow(Flow) {}
};

class Graph
{
public:
	int n;
	vector<vector<int> > g;// ребра графа = числа-указатели на реальные ребра в AllEdges
	vector<Edge> AllEdges; // Реальные ребра графа
	vector<int> ptr, d;
	Graph(int n = 1) : n(n) { g.assign(n + 1, vector<int>()); }

	void AddNotOrientedEdge(int From, int To, int Len)
	{
		Edge e1 = Edge(To, Len, 0);
		g[From].push_back(AllEdges.size());
		AllEdges.push_back(e1);
		Edge e2 = Edge(From, 0, 0);
		g[To].push_back(AllEdges.size());
		AllEdges.push_back(e2);
	}

	int bfs(int s)
	{
		int qHead = 0, qTail = 0;
		int *q = new int[n + 1];
		q[qTail++] = s;
		d.assign(n + 1, -1); d[s] = 0;
		while (qHead < qTail)
		{
			int v = q[qHead++];
			for (int i = 0; i < g[v].size(); i++)
			{
				Edge e = AllEdges[g[v][i]];
				int to = e.vTo;
				if (d[to] == -1 && e.Flow < e.Cap)
				{
					q[qTail++] = to;
					d[to] = d[v] + 1;
				}
			}
		}
		delete[] q;
		return d[n] != -1;
	}

	int dfs(int v, int flow)
	{
		if (!flow)  return 0;
		if (v == n)  return flow;
		for (int &i = ptr[v]; flow && i < (int)g[v].size(); i++)
		{
			int EdgeId = g[v][i];
			Edge e = AllEdges[EdgeId];
			int to = e.vTo;
			if (d[to] != d[v] + 1) continue;
			int pushed = dfs(to, min(flow, e.Cap - e.Flow));
			if (pushed)
			{
				AllEdges[EdgeId].Flow += pushed;
				AllEdges[EdgeId ^ 1].Flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	int Dinic(int Start)
	{
		int flow = 0;
		while (true)
		{
			if (!bfs(Start)) break;
			ptr.assign(n + 1, 0);
			while (int pushed = dfs(Start, INF)) flow += pushed;
		}
		return flow;
	}
};

Graph *g;
int cnt, i, j, k, m, n, c, x, Final, MaxFlow;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	Final = 1 + m + 2 * n + k + 1;
	g = new Graph(Final);
	for (i = 2; i <= 1 + m; i++)
	{
		scanf("%d", &c);
		g->AddNotOrientedEdge(1, i, c);
	}
	for (i = 1 + m + 2 * n + 1; i <= 1 + m + 2 * n + k; i++)
	{
		scanf("%d", &c);
		g->AddNotOrientedEdge(i, Final, c);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &cnt);
		for (j = 1; j <= cnt; j++)
		{
			scanf("%d", &x);
			g->AddNotOrientedEdge(x + 1, 1 + m + i, 1);
		}
	}
	for (i = 1; i <= n; i++) g->AddNotOrientedEdge(1 + m + i, 1 + m + n + i, 1);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &cnt);
		for (j = 1; j <= cnt; j++)
		{
			scanf("%d", &x);
			g->AddNotOrientedEdge(1 + m + n + i, 1 + m + 2 * n + x, 1);
		}
	}
	MaxFlow = g->Dinic(1);
	printf("%d\n", MaxFlow);
	return 0;
}
