#include <iostream>

int n, m, res;

int gcd(int a, int b)
{
	if (b > 0) return gcd(b, a % b);
	return a;
}

int main() {
	scanf("%d %d", &m, &n);
	res = m + n - gcd(m, n);
	printf("%d\n", res);
	return 0;
}
