#include <iostream>
#include <string.h>

using namespace std;

char s[2001];
int len, dp[2001][2001];

//Реализация функции f(n, k).
int f(int n, int k)
{
	if (k < 0) return 0;
	if (n == len) return (k == 0);
	if (dp[n][k] != -1) return dp[n][k];
	if (s[n] == '(') return dp[n][k] = f(n + 1, k + 1);
	if (s[n] == ')') return dp[n][k] = f(n + 1, k - 1);
	return dp[n][k] = (f(n + 1, k - 1) + f(n + 1, k + 1)) % 301907;
}

int main() {
	gets(s); len = strlen(s);
	memset(dp, -1, sizeof dp);
	printf("%d\n", f(0, 0));
	return 0;
}
