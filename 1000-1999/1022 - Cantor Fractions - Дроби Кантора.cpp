#include <iostream>
#include <math.h>

int main() {
	int n, k, r;
	while (scanf("%d", &n) == 1) {
		k = int(sqrt(2.0 * n) + 0.5); // 0 < k*(k+1)^0.5-(k^2)^0.5 < 0.5
		r = k*(k + 1) / 2 - n;
		printf("%d/%d\n", 1 + r, k - r);
	}
	return 0;
}
