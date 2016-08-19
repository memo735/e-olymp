//Author Nurlan Sofiyev

#include <iostream>

using namespace std;

#define N 1001
#define INF 2000000000

long dp[N][N];

int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);
	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= a; ++j) dp[i][j] = INF;

	dp[1][1] = 4;
	for (int i = 1; i <= a; ++i)
	{
		for (int buf = 1; buf <= i; ++buf)
		{
			long tmp = dp[i - buf][buf] + 2;
			if (tmp < dp[i][buf]) dp[i][buf] = tmp;
			for (int j = 1; j < buf; ++j)
			{
				if (dp[i][j] + 2 < dp[i][buf]) dp[i][buf] = dp[i][j] + 2;
				else if (dp[i][buf] + 2 < dp[i][j]) dp[i][j] = dp[i][buf] + 2;
			}
		}
	}
	long MIN = dp[a][a];
	if (b == 1)
	{
		MIN = INF;
		for (int i = 1; i <= a; ++i) if (dp[a][i] < MIN) MIN = dp[a][i];
		cout << MIN;
		return 0;
	}
	a = b;
	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= a; ++j) dp[i][j] = INF;

	dp[1][1] = MIN;
	for (int i = 1; i <= a; ++i)
	{
		for (int buf = 1; buf <= i; ++buf)
		{
			long tmp = dp[i - buf][buf] + 2;
			if (tmp < dp[i][buf]) dp[i][buf] = tmp;
			for (int j = 1; j < buf; ++j)
			{
				if (dp[i][j] + 2 < dp[i][buf]) dp[i][buf] = dp[i][j] + 2;
				else if (dp[i][buf] + 2 < dp[i][j]) dp[i][j] = dp[i][buf] + 2;
			}
		}
	}
	MIN = INF;
	for (int i = 1; i <= a; ++i) if (dp[a][i] < MIN) MIN = dp[a][i];
	cout << MIN;
	return 0;
}
