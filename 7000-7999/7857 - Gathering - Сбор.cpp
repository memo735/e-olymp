#include <algorithm>
#include <vector>

using namespace std;

int n;
long a, b, d, e, f, r, z, x[100000], y[100000], q[200000];

long m(long *a, int n)
{
	nth_element(a, a + n / 2, a + n);
	return a[n / 2];
}

void c(long v, long w) {
	if (a > v - w || v - w > b || e > v + w || v + w > f) return;
	long s = 0;
	for (int i = 0;i < n;i++)s += abs(x[i] - v) + abs(y[i] - w);
	if (s < r)r = s;
}

int main() {
	int i;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) scanf("%ld %ld\n", &x[i], &y[i]);
	scanf("%ld\n", &d);
	a = e = -1e18;r = b = f = 1e18;
	for (i = 0;i < n;i++) {
		a = max(a, x[i] - y[i] - d);
		b = min(b, x[i] - y[i] + d);
		e = max(e, x[i] + y[i] - d);
		f = min(f, x[i] + y[i] + d);
	}
	if (a > b || e > f)
	{
		printf("impossible\n");
		return 0;
	}
	c(m(x, n), m(y, n));
	long g[2] = { a,b }, h[2] = { e,f }, p[4][3] = { { a,1 },{ b,1 },{ e,-1 },{ f,-1 } };
	for (i = 0;i < 16;i++)
		c((g[i & 1] + h[i >> 1 & 1] + (i >> 2 & 1)) / 2, h[i >> 1 & 1] - (g[i & 1] + h[i >> 1 & 1] + (i >> 3)) / 2);
	for (i = 0;i < 4;i++) {
		for (int j = 0;j < n;j++) {
			q[j * 2] = x[j];
			q[j * 2 + 1] = p[i][0] + p[i][1] * y[j];
		}
		z = m(q, n * 2);
		c(z, p[i][1] * z - p[i][0] * p[i][1]);
	}
	printf("%ld\n", r);
	return 0;
}
