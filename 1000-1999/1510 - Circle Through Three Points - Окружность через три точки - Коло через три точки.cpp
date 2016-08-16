#include <iostream>
#include <math.h>

using namespace std;

#define EPS 1e-6

double x_1, y_1, x_2, y_2, x_3, y_3, xc, yc, r, r1;

int kramer(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y)
{
	double d = a1 * b2 - a2 * b1;
	double dx = c1 * b2 - c2 * b1;
	double dy = a1 * c2 - a2 * c1;
	if (!d) return (dx == 0.0) + 1;
	*x = dx / d; *y = dy / d;
	return 0;
}

//Функция midperpend по заданным координатам концов отрезка A(x1, y1) и B(x2, y2)
//строит серединный перпендикуляр ax + by + c = 0. Поскольку вектора AB(x2 – x1, y2 – y1) и (a, b) коллинеарны,
//то a = x2 – x1, b = y2 – y1. Серединный перпендикуляр проходит через точку M((x1+x2)/2, (y1+y2)/2) – середину отрезка АВ,
//значит ax + by + c = (x2 – x1)*(x1+x2)/2 + (y2 – y1)(y1+y2)/2 + c = 0, откуда c = (x1^2-x2^2+y1^2-y2^2)/2.
void midperpend(double x1, double y1, double x2, double y2, double *a, double *b, double *c)
{
	*a = x2 - x1;
	*b = y2 - y1;
	*c = (x1*x1 - x2*x2 + y1*y1 - y2*y2) / 2;
}

//Функция circle по трем точкам A(x1, y1), В(x2, y2) и С(x3, y3) находит центр окружности (xc, yc) и радиус r,
//который через них проходит.Для этого строятся серединные перпендикуляры к отрезкам AB и AC, после чего
//находится точка их пересечения О – центр искомой окружности.Радиус r вычисляется как расстояние между точками O и A.
void circle(double x1, double y1, double x2, double y2, double x3, double y3, double *xc, double *yc, double *r)
{
	double a1, b1, c1, a2, b2, c2;
	midperpend(x1, y1, x2, y2, &a1, &b1, &c1);
	midperpend(x1, y1, x3, y3, &a2, &b2, &c2);
	kramer(a1, b1, -c1, a2, b2, -c2, xc, yc);
	*r = sqrt((x1 - *xc)*(x1 - *xc) + (y1 - *yc)*(y1 - *yc));
}

int main() {
	while (scanf("%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3) == 6)
	{
		circle(x_1, y_1, x_2, y_2, x_3, y_3, &xc, &yc, &r);
		if (fabs(xc) < EPS) printf("x^2");
		else
		{
			printf("(x");
			printf(xc >= 0.0 ? " - " : " + ");
			printf("%.3lf)^2", fabs(xc));
		}
		printf(" + ");
		if (fabs(yc) < EPS) printf("y^2");
		else
		{
			printf("(y", fabs(xc));
			printf(yc >= 0.0 ? " - " : " + ");
			printf("%.3lf)^2", fabs(yc));
		}
		printf(" = %.3lf^2\n", r);
		printf("x^2 + y^2");
		if (fabs(xc) > EPS)
		{
			printf(xc > 0.0 ? " - " : " + ");
			printf("%.3lfx", 2 * fabs(xc));
		}
		if (fabs(yc) > EPS)
		{
			printf(yc > 0.0 ? " - " : " + ");
			printf("%.3lfy", 2 * fabs(yc));
		}
		r1 = xc*xc + yc*yc - r*r;
		if (fabs(r1) > EPS)
		{
			printf(r1 > 0.0 ? " + " : " - ");
			printf("%.3lf", fabs(r1));
		}
		printf(" = 0\n\n");
	}
	return 0;
}
