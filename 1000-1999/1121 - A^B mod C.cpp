#include <iostream>

using namespace std;

long mult(long a, long b, long c)
{
	long res = 0;
	a = a % c;
	while (b)
	{
		if (b & 1)
		{
			res += a;
			if (res > c) res -= c;
		}
		a <<= 1;
		if (a > c) a -= c;
		b >>= 1;
	}
	return res;
}

//Вычисление a^b mod c согласно приведенной в анализе задачи рекуррентности.
long pow(long a, long b, long c)
{
	long temp;
	if (b == 0) return 1;
	temp = pow(a, b / 2, c);
	if (b % 2 == 0) return mult(temp, temp, c);
	return mult(mult(temp, temp, c), a, c);
}

int main() {
	long a, b, c, res;
	while (scanf("%ld %ld %ld", &a, &b, &c) == 3)
	{
		a = a % c;
		if (a == 1) res = 1;
		else res = pow(a, b, c);
		printf("%ld\n", res);
	}
	return 0;
}
