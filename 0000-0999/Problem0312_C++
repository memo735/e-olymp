#include<stdio.h>

int f[1010][20][20], N;

inline int max3(int a, int b, int c)
{
	int ret = a;
	if (ret < b) ret = b;
	if (ret < c) ret = c;
	return ret;
}

inline int max2(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int white, black, i, j;
	while (scanf("%d%d", &white, &black) != EOF)
	{
		N++;
		for (i = 1; i <= 15; i++)
		{
			f[N][i][0] = max2(f[N - 1][i - 1][0] + white, f[N - 1][i][0]);
			f[N][0][i] = max2(f[N - 1][0][i - 1] + black, f[N - 1][0][i]);
			for (j = 1; j <= 15; j++)
				f[N][i][j] = max3(f[N - 1][i - 1][j] + white, f[N - 1][i][j - 1] + black, f[N - 1][i][j]);
		}
	}
	printf("%d\n", f[N][15][15]);
	return 0;
}
