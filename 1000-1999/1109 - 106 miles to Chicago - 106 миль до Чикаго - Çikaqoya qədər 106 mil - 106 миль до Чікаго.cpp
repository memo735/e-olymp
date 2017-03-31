#include <iostream>

using namespace std;

double cost[101][101];
int i, j, k, m, n, x, y, p;

void floyd()
{
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (cost[i][j] < cost[i][k] * cost[k][j])
					cost[i][j] = cost[i][k] * cost[k][j];

}

int main()
{
	while (cin >> n && n)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cost[i][j] = i == j ? 1 : 0;

		scanf("%d", &m);
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &x, &y, &p);
			cost[x][y] = cost[y][x] = p / 100.0;
		}
		floyd();
		printf("%.6lf percent\n", cost[1][n] * 100);
	}
	return 0;
}
