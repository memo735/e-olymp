#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 21
#define INF 0x3F3F3F3F

int cnt, best, n, i, j, k;
int m[MAX][MAX], dp[1 << MAX][MAX];

int solve(int mask, int last)
{
	int &res = dp[mask][last];
	if (res == INF)
	{
		mask ^= 1 << last;
		for (int i = 1; i < n + 1; ++i)
			if (mask & 1 << i) res = min(res, solve(mask, i) + m[i][last]);
	}
	return res;
}

int main()
{
	scanf("%d", &n);

	for (i = 0; i < n + 1; i++)
		for (j = 0; j < n + 1; j++) scanf("%d", &m[i][j]);

	for (k = 0; k < n + 1; k++)
		for (i = 0; i < n + 1; i++)
			for (j = 0; j < n + 1; j++)
				if (m[i][k] + m[k][j] < m[i][j]) m[i][j] = m[i][k] + m[k][j];

	memset(dp, 0x3F, sizeof dp);
	dp[1][0] = 0; best = INF;
	for (i = 1; i < n + 1; i++) dp[1 | 1 << i][i] = m[0][i];
	for (i = 1; i < n + 1; i++) best = min(best, solve((1 << n + 1) - 1, i) + m[i][0]);
	printf("%d\n", best);
	return 0;
}
