#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d^%d %d^%d", &a, &b, &c, &d);
	//Проведем сравнение прологарифмированных выражений b*lg a и d*lg c.
	if (b * log(a) < d * log(c)) printf("%d^%d\n", c, d);
	else printf("%d^%d\n", a, b);
	return 0;
}
