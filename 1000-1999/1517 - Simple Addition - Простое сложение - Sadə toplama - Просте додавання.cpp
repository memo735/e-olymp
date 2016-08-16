#include <iostream>

using namespace std;

long p, q;

//Функция g(p) вычисляет сумму значений функции f(n) для значений аргумента n от 1 до p.
long g(long p)
{
	long t = p % 10;
	if (!p) return 0;
	return t * (1 + t) / 2 + p / 10 * 45 + g(p / 10);
}

//Значение функции S(p, q) считаем как g(q) – q(p – 1).
long s(long p, long q)
{
	return g(q) - g(p - 1);
}

int main() {
	while (scanf("%ld %ld", &p, &q), p + q >= 0) printf("%ld\n", s(p, q));
	return 0;
}
