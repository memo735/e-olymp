#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct node
{
	int len, price[301], num[301];
} a[55];

int main()
{
	int i, j, n, w, tem, dp[53][301], path[53][301];
	while (~scanf("%d%d", &n, &w))
	{
		for (i = 1;i <= w + 1;i++)
		{
			scanf("%d", &a[i].len);
			for (j = 1; j <= a[i].len; j++) scanf("%d", &a[i].price[j]);
			for (j = 1; j <= a[i].len; j++) scanf("%d", &a[i].num[j]);
		}
		memset(dp, -1, sizeof dp);
		for (i = 1; i <= a[1].len; i++)
		{
			tem = min(a[1].num[i], n);
			dp[1][tem] = tem*a[1].price[i];
			path[1][tem] = a[1].price[i];
		}
		for (i = 2; i <= w + 1; i++)
		{
			for (j = 0; j <= n; j++)
			{
				if (dp[i - 1][j] == -1) continue;
				for (int k = 1; k <= a[i].len; k++)
				{
					tem = min(n, j + a[i].num[k]);
					if (dp[i][tem]<dp[i - 1][j] + (tem - j)*a[i].price[k] || dp[i][tem] == dp[i - 1][j] + (tem - j)*a[i].price[k] && path[i][tem]>a[i].price[k])
					{
						path[i][tem] = path[i - 1][j];
						dp[i][tem] = dp[i - 1][j] + (tem - j)*a[i].price[k];
					}
				}
			}
		}
		int s1 = -1, s2 = 0;
		for (i = 0; i <= n; i++)
		{
			if (s1 < dp[w + 1][i])
			{
				s1 = dp[w + 1][i];
				s2 = path[w + 1][i];
			}
		}
		printf("%d\n%d\n", s1, s2);
	}
	return 0;
}
