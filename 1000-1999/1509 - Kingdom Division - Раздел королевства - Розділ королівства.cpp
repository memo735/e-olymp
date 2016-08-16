#include <iostream>

using namespace std;

int main() {
	double a, b, c, d;
	int cs = 0;
	while (scanf("%lf %lf %lf", &a, &b, &c), a != -1.0)
	{
		d = a * c / b;
		printf("Set %d:\n", ++cs);
		//Проверяем условие b > d1 и вычисляем площадь d2.
		//Искомая площадь d равна d1 + d2.
		if (b > d) printf("%.4lf\n", d + (a + d) * (c + d) / (b - d));
		else printf("Poor King!\n");
	}
	return 0;
}
