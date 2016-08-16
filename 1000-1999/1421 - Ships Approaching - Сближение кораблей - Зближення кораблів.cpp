#include <iostream>
#include <math.h>

using namespace std;

double t, xx1, yy1, xx2, yy2, v1, v2, A, B, temp, res;
double PI = acos(-1.0), EPS = 1e-9;

double sqr(double x) { return x*x; }

double dist(double t)
{
	return sqrt(sqr(xx2 - xx1 + t *(v2 * cos(B) - v1 * cos(A))) + sqr(yy2 - yy1 + t *(v2 * sin(B) - v1 * sin(A))));
}


int main() {
	scanf("%lf %lf %lf %lf", &xx1, &yy1, &xx2, &yy2);
	scanf("%lf %lf %lf %lf", &A, &v1, &B, &v2);
	//Переведем углы в радианную меру.
	A = A * PI / 180.0; B = B * PI / 180.0;
	//Находим t, при котором достигается минимум функции dist(t).
	t = (xx1 - xx2) * (v2 * cos(B) - v1 * cos(A)) + (yy1 - yy2) * (v2 * sin(B) - v1 * sin(A));
	temp = sqr(v1) + sqr(v2) - 2 * v1 * v2 * cos(A - B);
	//Значение temp близко к нулю, если корабли движутся параллельно.
	//Кратчайшее расстояние между ними можно положить равным расстоянию в точке t = 0.
	if (fabs(temp) < EPS) res = dist(0);
	else
	{
		t /= temp;
		if (t < 0) t = 0;
		res = dist(t);
	}
	printf("%.2lf\n", res);
	return 0;
}
