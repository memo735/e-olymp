#include <iostream>

using namespace std;

unsigned long PowMod(unsigned long x, unsigned long y, unsigned long n)
{
	if (!y) return 1;
	if (y & 1) return x * PowMod(x * x % n, y / 2, n) % n;
	return PowMod(x * x % n, y / 2, n);
}

int main() {
	//Читаем входные значения k, n, t, вычисляем m = 10^t.Находим x = k^n(mod 10^t) = (k mod m)^n (mod 10t).
	//Поскольку k < 10^19, то во избежание переполнения перед вызовом функции powmod следует найти остаток
	//от деления k на m. Таким образом значение первого аргумента k функции powmod будет не более 10^9 и
	//при вычислении k * k не будет переполнения. Выводим результат с номером теста cs.
	int cs = 1;
	unsigned long k, n, m, t, res;
	while (scanf("%lu %lu %lu", &k, &n, &t), k + n + t)
	{
		m = 1;
		for (int i = 0; i < t; i++) m *= 10;
		res = PowMod(k % m, n, m);
		printf("Case #%d: %ld\n", cs++, res);
	}
	return 0;
}
