#include <iostream>
#include <math.h>

using namespace std;

#define PI acos(-1.0)

int n, m, k;
double r, UpperS, DownS, Res;

void GetLine(double x1, double y1, double x2, double y2, double *a, double *b, double *c)
{
	*a = y2 - y1;
	*b = -(x2 - x1);
	*c = -x1*(y2 - y1) + y1*(x2 - x1);
}

//Точкой пересечения прямых a1x + b1y = c1 и a2x + b2y = c2 будет P(x, y).
void GetPoint(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y)
{
	double d = a1*b2 - a2*b1;
	*x = (c1*b2 - c2*b1) / d;
	*y = (a1*c2 - a2*c1) / d;
}

//Вычисление площади k - ого многоугольника. Точка P имеет кординаты(x, y), а d = OP^2.
double Area(double x, double y)
{
	double d = x*x + y*y;
	return n*d*sin(2 * PI / n) / 2;
}

double FindSquare(int k)
{
	double a1, b1, c1, a2, b2, c2, x, y;
	GetLine(r, 0, r*cos(2 * PI*k / n), r*sin(2 * PI*k / n), &a1, &b1, &c1);
	GetLine(r*cos(2 * PI / n), r*sin(2 * PI / n), r*cos(2 * PI*(k + 1) / n), r*sin(2 * PI*(k + 1) / n), &a2, &b2, &c2);
	GetPoint(a1, b1, -c1, a2, b2, -c2, &x, &y);
	return Area(x, y);
}

int main() {
	scanf("%d", &m);
	while (m--)
	{
		scanf("%lf %d %d", &r, &n, &k);
		if (k == n / 2) UpperS = PI*r*r;
		else UpperS = FindSquare(n / 2 - k);
		DownS = FindSquare(n / 2 - k + 1);
		Res = UpperS - DownS;
		printf("%.4lf\n", Res);
	}
	return 0;
}
