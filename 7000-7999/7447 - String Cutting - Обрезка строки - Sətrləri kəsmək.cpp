#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 101
#define INF 2100000000
int dp[MAX][MAX];
char s[MAX];

//Пусть Calc(l, r) – решение задачи на отрезке[l; r].
int Calc(int l, int r)
{
	if (l > r) return 0;
	if (l == r) return 1;
	if (dp[l][r] != -1) return dp[l][r];
	int &ans = dp[l][r] = INF;
	if (s[l] == s[r]) ans = min(ans, Calc(l + 1, r - 1));
	for (int i = l; i < r; i++) ans = min(ans, Calc(l, i) + Calc(i + 1, r));
	return ans;
}

int main() {
	gets(s);
	int n = strlen(s);
	memset(dp, -1, sizeof dp);
	printf("%d\n", Calc(0, n - 1));
	return 0;
}
