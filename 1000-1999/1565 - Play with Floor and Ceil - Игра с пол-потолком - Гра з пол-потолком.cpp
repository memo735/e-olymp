#include <iostream>
#include <math.h>

using namespace std;

long x, k, p, q, n, m, g, u, t;

void gcdext(long a, long b, long* d, long* x, long* y)
{
	long s;
	if (b == 0)
	{
		*d = a; *x = 1; *y = 0;
		return;
	}
	gcdext(b, a % b, d, x, y);
	s = *y;
	*y = *x - (a / b) * (*y);
	*x = s;
}

int main() {
	int tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%lld %lld", &x, &k);
		if (x % k == 0) { p = 0; q = k; }
		else
		{
			n = int(floor(1.0 * x / k));
			m = int(ceil(1.0 * x / k));
			gcdext(n, m, &g, &t, &u);
			p = t * x; q = u * x;
		}
		printf("%ld %ld\n", p, q);
	}
	return 0;
}
