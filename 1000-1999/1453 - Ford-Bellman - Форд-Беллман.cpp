#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10002
#define INF 0x3F3F3F3F

int k, i, n, m, x[MAX], y[MAX], w[MAX], d[MAX];

void Bellman_Ford()
{
	int i, j;
	memset(d, 0x3F, sizeof d);
	d[1] = 0;
	for (i = 1; i <= n; i++) // for stage = 1, 2, ..., n
		for (j = 1; j <= m; j++) // for each edge try to relax it
			if (d[x[j]] < INF && d[y[j]] > d[x[j]] + w[j]) d[y[j]] = d[x[j]] + w[j];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) scanf("%d %d %d", &x[i], &y[i], &w[i]);
	Bellman_Ford();
	for (i = 1; i <= n; i++)
		if (d[i] == INF) d[i] = 30000;
	for (i = 1; i < n; i++) printf("%d ", d[i]);
	printf("%d\n", d[n]);
	return 0;
}
