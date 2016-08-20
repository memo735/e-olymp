#include <iostream>
#include <math.h>

using namespace std;

int s, x, y, z, zs, res;

int main() {
	scanf("%d", &s); s *= 2;
	for (int x = 1; x <= s; x++) {
		if (s % x == 0)
		{
			y = s / x;
			if (y < x) break;
			z = x * x + y * y;
			zs = (int)sqrt(z);
			if (zs * zs == z) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
