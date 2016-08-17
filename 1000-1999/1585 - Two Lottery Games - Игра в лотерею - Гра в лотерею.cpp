#include <iostream>

using namespace std;

int n, m, k, x;
double res;

int Combinezon(int k, int n)
{
	int res = 1;
	if (k > n) return 0;
	if (k > n - k) k = n - k;
	for (int i = 1; i <= k; i++) res = res * (n - i + 1) / i;
	return res;
}

int main() {
	while (scanf("%d %d %d", &n, &m, &k) == 3)
	{
		for (res = 0, x = k; x <= m; x++)
			res += Combinezon(x, m) * Combinezon(m - x, n - m);
		res = res / Combinezon(m, n);
		printf("%.4lf\n", res);
	}
	return 0;
}
