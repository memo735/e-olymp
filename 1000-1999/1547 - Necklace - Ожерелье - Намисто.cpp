#include <iostream>
#include <math.h>

using namespace std;

double f(int v, int v0, int n)
{
	return 0.3 * sqrt(v * n - v0 * n * n);
}

int main() {
	int n, v, v0;
	double r1, r2;
	while (scanf("%d %d", &v, &v0), v + v0 > 0)
	{
		n = int(0.5 * v / v0);
		if (v <= v0 * n)
		{
			printf("0\n");
			continue;
		}
		r1 = f(v, v0, n);
		r2 = f(v, v0, n + 1);
		if (r2 > r1) n++;
		if (fabs(r1 - r2) < 1e-7) printf("0\n");
		else printf("%d\n", n);
	}
	return 0;
}
