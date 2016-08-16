#include <iostream>

using namespace std;

int main() {

	long a, b, cs = 1, res;
	while (scanf("%ld %ld", &a, &b), a + b > 0)
	{
		res = a * (a - 1) * b * (b - 1) / 4;
		printf("Case %d: %ld\n", cs++, res);
	}
	return 0;
}
