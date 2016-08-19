#include <iostream>

using namespace std;

int i, j, n, val, flag;

int main() {
	scanf("%d", &n); flag = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &val);
			if (i > j) continue;
			if (val) printf("%d %d\n", i, j), flag = 0;
		}
	}
	if (flag) puts("");
	return 0;
}
