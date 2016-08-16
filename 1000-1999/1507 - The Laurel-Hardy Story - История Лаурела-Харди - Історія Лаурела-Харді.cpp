#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int i = 0, t;
	double b, r, d, ax, h1, h2;
	scanf("%d", &t);
	while (i++ < t)
	{
		scanf("%lf %lf %lf", &r, &d, &h1);
		printf("Case %d: ", i);
		b = asin((r - h1) / r) - asin((r - d) / r);
		if (b == 0.0)
		{
			printf("%0.4lf\n", h1);
			continue;
		}
		ax = 2 * sqrtl(r*r - (d - r)*(d - r)) + h1 / sin(b);
		h2 = ax * sin(b);
		printf("%0.4lf\n", h2);
	}
	return 0;
}
