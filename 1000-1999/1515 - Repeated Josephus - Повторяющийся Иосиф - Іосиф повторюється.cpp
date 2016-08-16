#include <iostream>

using namespace std;

int last(int n)
{
	if (n == 1)   return 1;
	if (n % 2 == 0) return 2 * last(n / 2) - 1;
	return 2 * last((n - 1) / 2) + 1;
}

int main() {
	//Переменная r содержит количество повторений процедуры казни (изначально r = 0). По заданному
	//входному n ищем номер уцелевшего k.Если он не равен n, то повторяем в цикле процедуру казни.
	int i = 0, k, n, r, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		r = 0;
		while ((k = last(n)) != n) r++, n = k;
		printf("Case %d: %d %d\n", ++i, r, n);
	}
	return 0;
}
