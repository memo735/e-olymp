#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b > 0) return gcd(b, a % b);
	return a;
}

int main() {
	int a, b, res;
	while (scanf("%d %d", &a, &b), a)
	{
		res = abs(a - b); a = b;
		while (scanf("%d", &b), b)
		{
			res = gcd(res, abs(a - b));
			a = b;
		}
		printf("%d\n", res);
	}
	return 0;
}
