#include <iostream>
#include <string.h>

using namespace std;

#define MAX 101
int dp[MAX][MAX][MAX];

//Функция f(n, leftSide, rightSide) возвращает количество способов, которыми можно
//расположить n домов, так, чтобы слева было видно leftSide, а справа rightSide домов.
int f(int n, int sol, int sag)
{
	if (n == 1) return sol == 1 && sag == 1 ? 1 : 0;
	if (sol < 1 || sag < 1) return 0;
	if (dp[n][sol][sag] != -1) return dp[n][sol][sag];
	dp[n][sol][sag] = (int)(((long)f(n - 1, sol - 1, sag) + (long)f(n - 1, sol, sag - 1) +
		(n - 2)*(long)f(n - 1, sol, sag)) % 1000000007);
	return dp[n][sol][sag];
}

int main() {
	int n, leftSide, rightSide;
	while (scanf("%d %d %d", &n, &leftSide, &rightSide) == 3)
	{
		memset(dp, -1, sizeof dp);
		printf("%d\n", f(n, leftSide, rightSide));
	}
	return 0;
}
