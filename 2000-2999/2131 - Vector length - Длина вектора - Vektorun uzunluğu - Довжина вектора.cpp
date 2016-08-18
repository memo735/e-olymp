#include <iostream>
#include <math.h>

using namespace std;

double sqr(double x) { return x*x; }

int main() {
	double x1, x2, y1, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	printf("%.6lf\n", sqrt(sqr(x2 - x1) + sqr(y2 - y1)));
	return 0;
}
