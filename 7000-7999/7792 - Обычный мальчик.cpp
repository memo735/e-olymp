#include <iostream>
#include <math.h>

using namespace std;

int Div100(int n)
{
	int c, i, res = 1;
	for (i = 2; i <= int (sqrt(n)); i++)
	{
		if (n % i == 0)
		{
			c = 0;
			while (n % i == 0)
			{
				n /= i; c++;
			}
			res *= c + 1;
		}
	}
	if (n > 1) res *= 2;
	return res >= 100;
}

int main() {
	long long x;
	scanf("%lld", &x);
	//Если x ≥ 5 040 000, то выводим(x / 50 400 + 1) * 50 400.
	if (x >= 5040000)
	{
		printf("%lld\n", (x / 50400 + 1) * 50400);
		return 0;
	}
	//Перебираем i от x до 101 * x / 100. Если количество делителей у числа i не меньше 100, то выводим его.
	for (int i = x; 100 * i <= 101 * x; i++) {
		if (Div100(i))
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
