#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b, c, d, p, s, r;
	int i = 0, n; cin >> n;
	while (n--)
	{
		cin >> p >> a >> b;
		c = p / 2 - a; d = p / 2 - b;
		//Если четырехугольник со сторонами a, b, c, d существует (их длины положительны),
		//то вычисляем радиус вписанной окружности и выводим результат. Иначе
		//выводим сообщение о невозможности построения четырехугольника.
		if (c > 0 && d > 0)
		{
			s = sqrt(a * b * c * d);
			r = 2 * s / p;
			printf("Case %d: %.6lf\n", ++i, r);
		}
		else printf("Case %d: Eta Shombhob Na.\n", ++i);
	}
	return 0;
}
