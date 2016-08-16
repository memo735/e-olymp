#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double r, n, res;
	while (scanf("%lf %lf", &r, &n) == 2)
	{
		res = 2 * r / sqrt(n*n - 1);
		printf("%.6lf\n", res);
	}
	return 0;
}
