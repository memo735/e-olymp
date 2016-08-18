#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double ax, ay, bx, by, ma, mb, sc, res;
	scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
	ma = sqrt(ax*ax + ay*ay);
	mb = sqrt(bx*bx + by*by);
	sc = ax * bx + ay * by;
	printf("%.5lf\n", acos(sc / (ma * mb)));
	return 0;
}
