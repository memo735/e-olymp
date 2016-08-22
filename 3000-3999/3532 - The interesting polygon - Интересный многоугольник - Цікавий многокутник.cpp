#include <iostream>
#include <math.h>

using namespace std;

#define EPS 1e-11
#define PI acos(-1.0)

double sqr(double x) { return x*x; }

int i, n;
double fi, Left, Right, Middle;

int main() {
	//Читаем количество сторон n. Устанавливаем границы бинарного поиска
	//для радиуса описанной окружности [Left ..Right] = [n / 2 ..n^2].
	scanf("%d", &n);
	Left = n / 2; Right = n * n;

	//Пока длина отрезка [Left ..Right] не меньше EPS, продолжаем бинарный поиск.
	while (fabs(Right - Left) > EPS)
	{
		//Делим отрезок [Left ..Right] пополам точкой Middle. Полагая радиус окружности равным
		//Middle, вычисляем в переменной fi сумму углов, стягивающих стороны многоугольника.
		Middle = (Left + Right) / 2;
		for (fi = 0, i = 1; i <= n; i++)
		{
			double angle = (2 * sqr(Middle) - sqr(i)) / (2 * sqr(Middle));

			//Если треугольника со сторонами i, Middle, Middle составить нельзя, то значение
			//косинуса соответствующего угла может выходить за пределы отрезка[-1, 1].
			//Следовательно необходимо уменьшать величину радиуса описанной окружности.
			if (angle < -1.0 || angle > 1.0)
			{
				fi = 100;
				break;
			}
			fi += acos(angle);
		}
		//В зависимости от найденной суммы углов fi, корректируем отрезок поиска.
		if (fi > 2 * PI) Left = Middle;
		else Right = Middle;
	}
	printf("%.8lf\n", Left);
	return 0;
}
