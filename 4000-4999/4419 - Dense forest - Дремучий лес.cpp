#include <iostream>
#include <algorithm>

using namespace std;

#define EPS 1e-9

double a, f, g, vf, vp, Left, Right;

double sqr(double x) { return x*x; }

double t(double x)
{
	return sqrt(sqr(x) + sqr(1 - a)) / vp + sqrt(sqr(a) + sqr(1 - x)) / vf;
}

int main() {
	scanf("%lf %lf %lf", &vp, &vf, &a);
	//Запускаем тернарный поиск для нахождения минимума функции t(x) на отрезке [0; 1].
	Left = 0; Right = 1;
	while (Right - Left >= EPS)
	{
		f = Left + (Right - Left) / 3;
		g = Right - (Right - Left) / 3;
		if (t(f) < t(g)) Right = g;
		else Left = f;
	}
	//Выводим ответ – абсциссу точки, в которой инспекция СЭС должна войти в лес
	printf("%.9lf\n", Left);
	return 0;
}
