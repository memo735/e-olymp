#include <iostream>
#include <math.h>

using namespace std;

long g(long n)
{
	long i, up, res = 0;
	for (i = 1; i <= (long)sqrt(n); i++) res += n / i;
	up = n / ((long)sqrt(n) + 1);
	for (i = 1; i <= up; i++) res += i * (n / i - n / (i + 1));
	return res;
}

int main() {
	long a, b;
	while (scanf("%ld %ld", &a, &b), a + b) printf("%ld\n", g(b) - g(a - 1));
	return 0;
}
