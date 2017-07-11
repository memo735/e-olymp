#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int tt;
	scanf("%d", &tt);
	for (int ii = 0; ii < tt; ++ii) {
		long a, n;
		scanf("%ld%ld", &a, &n);
		long k = a / n, res = n ^ a;
		for (long i = max(k - 2, 0L); i <= k + 2; ++i) res = min(res, (i * n) ^ a);
		printf("%ld\n", res);
	}
	return 0;
}
