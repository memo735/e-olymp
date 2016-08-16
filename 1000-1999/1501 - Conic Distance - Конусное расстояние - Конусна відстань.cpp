#include <iostream>
#include <math.h>

using namespace std;

const double PI = acos(-1.0);

int main()
{
	double l, r, h, a1, d1, a2, d2, da, fi;
	while (scanf("%lf %lf %lf %lf %lf %lf", &r, &h, &d1, &a1, &d2, &a2) == 6)
	{
		a1 *= PI / 180; a2 *= PI / 180;
		da = fabs(a2 - a1);
		if (da > PI) da = 2 * PI - da;
		//Вычисляем длину образующей l и угол j, на который отображается угол dA на развертке.
		//По теореме косинусов находим расстояние между точками p1 и p2 и выводим результат.
		l = sqrt(r*r + h*h);
		fi = da * r / l;
		l = sqrt(d1*d1 + d2*d2 - 2 * d1*d2*cos(fi));
		printf("%.2lf\n", l);
	}
	return 0;
}
