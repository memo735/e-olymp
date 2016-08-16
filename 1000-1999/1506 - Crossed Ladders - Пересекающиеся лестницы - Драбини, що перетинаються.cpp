#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double a, b, c, c1, d, x, y, Left, Right;
	while (scanf("%lf %lf %lf", &x, &y, &c) == 3)
	{
		//Установим left = 0, right = min(x, y).
		//Далее в цикле будет иметь место неравенство left ≤ d ≤ right.
		Left = 0;
		if (x < y) Right = x;
		else Right = y;
		d = (Left + Right) / 2;
		do
		{
			//Вычисляем значения a, b, c.
			a = sqrt(x*x - d*d);
			b = sqrt(y*y - d*d);
			c1 = 1 / (1 / a + 1 / b);

			//Если найденное значение c1 меньше искомого с, то необходимо уменьшить
			//верхнюю границу d. Иначе следует увеличить его нижнюю границу.
			if (c1 < c) Right = (Left + Right) / 2;
			else Left = (Left + Right) / 2;
			d = (Left + Right) / 2;
			//Вычисления проводим до требуемой в ответе точности (четыре десятичных знака).

		} while (fabs(c1 - c) > 0.00001);
		printf("%.3lf\n", d);
	}
	return 0;
}
