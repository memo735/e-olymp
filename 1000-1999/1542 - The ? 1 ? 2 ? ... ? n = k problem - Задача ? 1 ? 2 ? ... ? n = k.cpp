#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n, k, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		//Для каждого теста вводим значение k и находим его модуль.
		scanf("%d", &k); k = abs(k);

		//Отдельно обрабатываем случай k = 0.
		if (!k) printf("3\n");
		else
		{
			//Находим положительный корень n квадратного уравнения, приведенного выше. Увеличиваем n на 1 до
			//тех пор, пока сумма 1 + 2 + … + n = n(n+1)/2 и значение k не будут иметь одинаковую четность.
			n = (int)ceil((-1 + sqrt(1 + 8.0 * k)) / 2);
			while (((1 + n) * n / 2 - k) % 2 == 1) n++;
			printf("%d\n", n);
		}
	}
	return 0;
}
