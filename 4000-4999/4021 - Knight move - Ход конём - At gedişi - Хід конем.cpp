#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int n, m, dp[51][51];
	scanf("%d %d", &n, &m);
	memset(dp, 0, sizeof dp);
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m;j++)
			dp[i][j] += dp[i - 1][j - 2] + dp[i - 2][j - 1];

	printf("%d\n", dp[n][m]);
	return 0;
}
