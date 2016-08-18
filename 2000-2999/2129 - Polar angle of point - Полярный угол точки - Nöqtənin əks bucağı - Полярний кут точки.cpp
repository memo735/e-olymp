#include <iostream>

using namespace std;

#define PI acos(-1.0)

int main() {
	double a, b, res;
	scanf("%lf %lf", &a, &b);
	res = atan2(b, a);
	if (res < 0) res += 2 * PI;
	printf("%.6lf\n", res);
	return 0;
}
