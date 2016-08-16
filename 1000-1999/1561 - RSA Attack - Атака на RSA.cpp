#include <iostream>
#include <algorithm>

using namespace std;

int mod_pow(int base, int expo, int mod)
{
	int result = 1;
	while (expo > 0)
	{
		if (expo % 2) result = result * base % mod;
		expo = expo >> 1;
		base = base * base % mod;
	}
	return result;
}

int main() {
	int c, e, n, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d %d", &e, &n, &c);

		//Начальное значение шифра с сохраним в переменной cOriginal.
		int cOriginal = c;
		c = mod_pow(c, e, n);
		int cPrev = cOriginal;
		//В начале i - ой итерации цикла while в переменной c содержится значение cOriginal^(e^i), а в переменной cPrev
		//значение cOriginal^(e^(i-1)).Цикл продолжается, пока не встретится такое k, для которого cOriginal = cOriginal^(e^k).

		while (c != cOriginal)
		{
			cPrev = c;
			c = mod_pow(c, e, n);
		}
		//По окончанию цикла искомое сообщение m находится в переменной cPrev.
		printf("%d\n", cPrev);
	}
	return 0;
}
