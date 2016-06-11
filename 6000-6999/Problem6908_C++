#include <iostream>
#include <string.h>

using namespace std;

double ans, pc[4], l, w, d, poss[25][25][25];
int n, p, i, j;

double dfs(int x, int w, int d, int z)
{
	if (z >= p) return 1;
	if (p - z > 3 * x) return 0;
	if (poss[x][w][d] >= 0) return poss[x][w][d];
	if (x == 1) return 0;
	poss[x][w][d] = dfs(x - 1, w + 1, d, z + 3)*pc[3] + dfs(x - 1, w, d + 1, z + 1)*pc[1] + dfs(x - 1, w, d, z)*pc[0];
	return poss[x][w][d];
}

int main()
{
	while (cin >> n >> p)
	{
		if (n == 0 && p == 0) break;
		cin >> w >> d >> l;
		pc[3] = w / (w + d + l);
		pc[1] = d / (w + d + l);
		pc[0] = l / (w + d + l);
		memset(poss, -1, sizeof poss);
		ans = 0;
		ans = dfs(n, 1, 0, 3)*pc[3] + dfs(n, 0, 1, 1)*pc[1] + dfs(n, 0, 0, 0)*pc[0];
		printf("%.1lf\n", ans * 100);
	}
}
