#include <iostream>
#include <math.h>

using namespace std;

int n, common;

int euler(int n)
{
	int i, result = n, div;
	common = 1;
	for (i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
		{
			div = 0;
			result -= result / i;
			while (n % i == 0) { n /= i; div++; }
			common *= div + 1;
		}
	if (n > 1)
	{
		result -= result / n;
		common *= 2;
	}
	return result;
}

int main() {
	while (scanf("%d", &n) == 1) printf("%d\n", n - euler(n) - common + 1);
	return 0;
}
