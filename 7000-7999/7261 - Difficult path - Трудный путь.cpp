#include <iostream>
#include <string.h>

using namespace std;

int main() {
	double d[2001][2001];
	int n, m;
	scanf("%d %d", &n, &m);
	memset(d, 0, sizeof d);
	d[0][n] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = n - i; j <= n + i; j++)
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) / 2;

	printf("%.9lf\n", d[n][n + m]);
	return 0;
}
