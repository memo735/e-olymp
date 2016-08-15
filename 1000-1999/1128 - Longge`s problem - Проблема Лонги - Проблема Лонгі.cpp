#include <iostream>

int main()
{
	long i, n, res, a, p;
	while (scanf("%lld", &n) == 1)
	{
		res = 1;
		for (i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				a = 0; p = 1;
				while (n % i == 0)
				{
					a++;
					p *= i;
					n /= i;
				}
				res *= (a + 1) * p - a * p / i;
			}
		}
		if (n > 1) res *= 2 * n - 1;
		printf("%ld\n", res);
	}
	return 0;
}
