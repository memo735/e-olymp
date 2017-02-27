#include <iostream>

using namespace std;

double ss;
int maxPrice;

int main() {
	scanf("%lf", &ss); maxPrice = int(100 * ss + 1e-7);
	//Поскольку a + b + c + d ≤ maxPrice, то a ≤ maxPrice / 4, b ≤(maxPrice – a) / 3,
	//c ≤(maxPrice – a – b) / 2.Используем эти ограничения при переборе.
	for (int a = 1; a <= maxPrice / 4; a++) {
		for (int b = a; b <= (maxPrice - a) / 3; b++)
			for (int c = b; c <= (maxPrice - a - b) / 2; c++)
			{
				//Из соотношения 1000000 * (a + b + c + d) = a * b * c * d выразим d :
				//d = 1000000 * (a + b + c) / (a * b * c - 1000000);
				//Значение d должно быть неотрицательным и целым.
				int s = 1000000 * (a + b + c), p = a * b * c - 1000000;
				if (p <= 0 || s % p != 0) continue;
				int d = s / p;
				//Должны выполняться соотношения c ≤ d и a + b + c + d ≤ maxPrice.
				if (d < c || a + b + c + d > maxPrice) continue;
				//Выводим найденное решение – четверку(a', b', c', d') = (a / 100, b / 100, c / 100, d / 100).
				printf("%.2f %.2f %.2f %.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
			}
	}
	return 0;
}
