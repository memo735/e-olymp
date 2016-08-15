#include <iostream>
#include <math.h>

using namespace std;

long factor(long n)
{
	long i, temp, c = 0, res = 0, nn = n;
	if (n == 1) return 2;
	for (i = 2; i <= sqrt(1.0*n); i++)
	{
		if (n % i == 0)
		{
			temp = 1;
			while (n % i == 0)
			{
				temp *= i;
				n /= i;
			}
			res += temp; c++;
		}
	}
	if (n > 1) res += n, c++;

	//Если n = nn, то n простое число. В этом случае f(n) = n + 1.
	if (n == nn) res++;

	//Если n не простое число, но количество простых делителей числа n равно
	//единице (c = 1), то n = p^a  для некоторого а. Тогда f(n) = p^a + 1.
	else if (c == 1) res++;
	return res;
}

int main() {
	long n, cs = 1;
	while (scanf("%ld", &n), n)
	{
		long res = factor(n);
		printf("Case %ld: %ld\n", cs++, res);
	}
	return 0;
}
