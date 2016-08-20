//Author: Nurlan Sofiyev

#include <iostream>
#include <algorithm>

using namespace std;

#define N 101
#define MAX 2000000000

long dp[N][N];

long answer(int a, long start_value)
{
	for (int i = 0; i <= a; ++i)
		for (int j = 0; j <= a; ++j) dp[i][j] = MAX;

	dp[1][1] = start_value;
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
	long Min = MAX;
	for (int i = 1; i <= a; ++i) if (dp[a][i] < Min) Min = dp[a][i];
	return Min;
}

int paint2D(int a, int b)
{
	long Min = answer(a, 4);
	if (b == 1) return Min;
	return answer(b, dp[a][a]);
}

int main()
{
	int *input = new int[3];
	cin >> input[0] >> input[1] >> input[2];
	sort(input, input + 3);
	long Min = paint2D(input[2], input[1]);
	if (input[0] == 1) cout << Min;
	else cout << answer(input[0], dp[input[1]][input[1]]);
	return 0;
}
