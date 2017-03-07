#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long n, k, l, *pep, *cwdis, *ccwdis;

void solve()
{
	for (int i = 0; i < n; i++)
	{
		long lstdis;
		if (i + 1 > k) lstdis = cwdis[i + 1 - k];
		else lstdis = 0;
		cwdis[i + 1] = lstdis + pep[i] * 2;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		long lstdis;
		if (n - i > k) lstdis = ccwdis[n - i - k];
		else lstdis = 0;
		ccwdis[n - i] = lstdis + (l - pep[i]) * 2;
	}
	long ans = 100000000000000000L;
	for (int i = 0; i <= n; i++) ans = min(ans, cwdis[i] + ccwdis[n - i]);
	for (int i = 1; i + k - 1 <= n; i++) // one circle for [ i, i + k - 1 ] cw
		ans = min(ans, cwdis[i - 1] + l + ccwdis[n - (i + k - 1)]);

	printf("%ld\n", ans);
}

int main() {
	scanf("%d %d %d", &n, &k, &l);
	pep = new long[n + 1];
	memset(pep, 0, (n + 1) * sizeof(long));
	cwdis = new long[n + 1];
	memset(cwdis, 0, (n + 1) * sizeof(long));
	ccwdis = new long[n + 1];
	memset(ccwdis, 0, (n + 1) * sizeof(long));
	for (int i = 0; i < n; i++) scanf("%lld", &pep[i]);
	solve();
	delete[] pep, cwdis, ccwdis;
	return 0;
}
