#include <iostream>

using namespace std;

double sqr(double x)
{
	return x*x;
}

int main() {
	double n, res;
	while (scanf("%lf", &n) == 1)
	{
		res = 1 - sqr(1 - n / 60.0);
		printf("%.6lf\n", res);
	}
	return 0;
}
