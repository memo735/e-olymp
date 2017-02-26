#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001
long a[MAX], dp[MAX];

long sqr(long a)
{
	return a * a;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%ld", &a[i]);
	dp[1] = 0;
	if (n == 2) dp[2] = sqr(a[2] - a[1]);
	else dp[2] = min(sqr(a[1] - a[2]), 3 * sqr(a[1] - a[3]) + sqr(a[2] - a[3]));
	for (int i = 3; i <= n; i++)
	{
		dp[i] = min(dp[i - 1] + sqr(a[i - 1] - a[i]), dp[i - 2] + 3 * sqr(a[i - 2] - a[i]));
		if (i < n) dp[i] = min(dp[i], dp[i - 1] + 3 * sqr(a[i - 1] - a[i + 1]) + sqr(a[i] - a[i + 1]));
	}
	printf("%ld\n", dp[n]);
	return 0;
}
