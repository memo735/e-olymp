#include <iostream>

int n, m;

void farrey(int a1, int b1, int a2, int b2)
{
	if (n < b1 + b2) return;
	if (m == a1 + a2 && n == b1 + b2) return;

	//Выражение m / n < (a1 + a2) / (b1 + b2) эквивалентно m * (b1 + b2) < n * (a1 + a2).
	if (m * (b1 + b2) < n * (a1 + a2)) printf("L"), farrey(a1, b1, a1 + a2, b1 + b2);
	else printf("R"), farrey(a1 + a2, b1 + b2, a2, b2);
}

int main() {
	//Запускаем функцию генерации всех дробей, начиная с(0 / 1, 1 / 0).
	while (scanf("%d %d", &m, &n), !(m == 1 && n == 1))
	{
		farrey(0, 1, 1, 0);
		printf("\n");
	}
	return 0;
}
