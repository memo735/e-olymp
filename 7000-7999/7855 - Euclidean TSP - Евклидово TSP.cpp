#include <stdio.h>
#include <math.h>

double n, p, s, v;

double tottime(double c) {
	return n*pow(log2(n), c*sqrt(2.0)) / (p*1e9) + s*(1 + 1 / c) / v;
}

int main() {
	scanf("%lf%lf%lf%lf", &n, &p, &s, &v);
	double lo = 0, hi = 1;
	while (tottime(hi) < tottime(hi / 2)) hi *= 2;
	for (int i = 0; i < 1000; ++i) {
		double c1 = (2 * lo + hi) / 3, c2 = (lo + 2 * hi) / 3;
		tottime(c1) > tottime(c2) ? lo = c1 : hi = c2;
	}
	printf("%.9lf %.9lf", tottime(lo), lo);
	return 0;
}
