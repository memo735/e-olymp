#include <iostream>
#include <string.h>

int n, m;
int w[1001]; // wait time
int d[1001][1001]; // shortest dist
int d0[1001][1001]; // original dist
int adj[2001][2001]; // adjacency list
bool a[2001][2001]; // for maxflow
bool b[2001], v[2001];

struct flight { int s, e, t; } f[1001];

bool flow(int x)
{
	if (b[x]) { b[x] = false;  return true; }
	v[x] = true;
	for (int i = 1; i <= adj[x][0]; i++)
	{
		int y = adj[x][i];
		if (a[x][y] && !v[y])
		{
			if (flow(y))
			{
				a[x][y] = false;
				a[y][x] = true;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &d0[i][j]);
			d[i][j] = d0[i][j];
		}
	}
	for (int k = 1; k <= n; k++) for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
	{
		if (d[i][j] > d[i][k] + w[k] + d[k][j]) d[i][j] = d[i][k] + w[k] + d[k][j];
	}
	for (i = 1; i <= m; i++) scanf("%d%d%d", &f[i].s, &f[i].e, &f[i].t);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (i == j) continue;
			// if i -> j chain is possible
			if (f[i].t + d0[f[i].s][f[i].e] + w[f[i].e] + d[f[i].e][f[j].s] + w[f[j].s] <= f[j].t ||
				f[i].e == f[j].s && f[i].t + d0[f[i].s][f[i].e] + w[f[i].e] <= f[j].t)
			{
				a[i][m + j] = true;
				adj[i][++adj[i][0]] = m + j;
				adj[m + j][++adj[m + j][0]] = i;
			}
		}
		b[m + i] = true;
	}
	int ans = m;
	for (i = 1; i <= m; i++)
	{
		memset(v, 0, sizeof v);
		if (flow(i)) ans--;
	}
	printf("%d\n", ans);
	return 0;
}
