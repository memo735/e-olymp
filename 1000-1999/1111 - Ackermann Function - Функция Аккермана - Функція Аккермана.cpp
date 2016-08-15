#include <iostream>

using namespace std;

int main() {
	int m, n, res;
	while (scanf("%lld %lld", &m, &n) == 2)
	{
		if (m == 0) res = n + 1;
		else
			if (m == 1) res = n + 2;
			else
				if (m == 2) res = 2 * n + 3;
				else res = (1 << n + 3) - 3;
				printf("%d\n", res);
	}
	return 0;
}
