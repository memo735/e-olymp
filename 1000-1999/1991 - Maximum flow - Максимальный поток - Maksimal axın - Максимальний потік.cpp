#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 120
#define INF 0x3F3F3F3F

int Cap[MAX][MAX], CurFlow[MAX][MAX];
int d[MAX], q[MAX], ptr[MAX];
int a, b, c, n, Edges, MaxFlow;

int bfs(int s)
{
	int qh = 0, qt = 0;
	q[qt++] = s;
	memset(d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt)
	{
		int v = q[qh++];
		for (int &to = ptr[v]; to <= n; to++)
			if (d[to] == -1 && CurFlow[v][to] < Cap[v][to])
			{
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[n] != -1;
}

int dfs(int v, int flow)
{
	if (!flow) return 0;
	if (v == n) return flow;
	for (int to = 1; to <= n; to++)
	{
		if (d[to] != d[v] + 1) continue;
		int pushed = dfs(to, min(flow, Cap[v][to] - CurFlow[v][to]));
		if (pushed)
		{
			CurFlow[v][to] += pushed;
			CurFlow[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}

int Dinic(int s)
{
	int flow = 0;
	while (1)
	{
		if (!bfs(s)) break;
		memset(ptr, 0, sizeof ptr);
		while (int pushed = dfs(s, INF)) flow += pushed;
	}
	return flow;
}

int main()
{
	scanf("%d %d", &n, &Edges);
	memset(Cap, 0, sizeof Cap);
	memset(CurFlow, 0, sizeof CurFlow);
	while (Edges--) scanf("%d %d %d", &a, &b, &c), Cap[a][b] += c, Cap[b][a] += c;
	MaxFlow = Dinic(1);
	printf("%d\n", MaxFlow);
	return 0;
}
