#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long n, res;
	int cs = 1;
	while (scanf("%ld", &n), n > 0)
	{
		res = int(ceil((3 + sqrt(9 + 8 * n)) / 2));
		printf("Case %d: %ld\n", cs++, res);
	}
	return 0;
}
