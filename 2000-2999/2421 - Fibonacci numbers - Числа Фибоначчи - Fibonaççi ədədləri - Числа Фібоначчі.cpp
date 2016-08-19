#include <iostream>
#include <map>

using namespace std;

#define MOD 100000000

map<long, long> F;

long gcd(long a, long b)
{
	return !b ? a : gcd(b, a % b);
}

long fib(long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (F[n]) return F[n];
	long k = n / 2;
	if (n % 2 == 1) return F[n] = (fib(k) * fib(k) + fib(k + 1) * fib(k + 1)) % MOD;
	return F[n] = (fib(k) * fib(k + 1) + fib(k - 1) * fib(k)) % MOD;
}

long a, b, d;

int main()
{
	while (scanf("%ld %ld", &a, &b) == 2)
	{
		printf("%ld\n", fib(gcd(a, b)));
	}
	return 0;
}
