#include <iostream>
#include <algorithm>

using namespace std;

int n;
double t;

double integral(double a, double k)
{
	double s = 0, tmp = a / k;
	if (t == 1) return max(a, k);
	if (tmp > 1) return a * (1 - t);
	if (tmp >= t) s = a * (tmp - t);
	else tmp = t;
	s += k * (1 - tmp * tmp) / 2;
	return s / (1 - t);
}

double f(int n, int a)
{
	if (!n) return a;
	double k = f(n - 1, 2 * a);
	return integral(a, k);
}

int main()
{
	while (scanf("%d %lf", &n, &t), n + t) printf("%.3lf\n", f(n, 1));
	return 0;
}
