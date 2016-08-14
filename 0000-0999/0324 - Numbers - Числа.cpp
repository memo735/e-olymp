#include <iostream>
#include <math.h>

using namespace std;

long ReqemCemi0X(long x)
{
	if (x <= 0) return 0;
	return x % 10 + ReqemCemi0X(x / 10);
}

long f(long x)
{
	if (x <= 0) return 0;
	long res = x / 10 * 45;
	long temp = x % 10;
	res = res + 10 * f(x / 10 - 1) + (temp + 1) * ReqemCemi0X(x / 10) + temp * (temp + 1) / 2;
	return res;
}

int main() {
	long a, b, res;
	scanf("%ld %ld", &a, &b);
	res = f(b) - f(a - 1);
	printf("%ld\n", res);
	return 0;
}
