#include <iostream>
#include <string.h>

using namespace std;

#define MAX 2011
#define EPS 1e-7

int i, j, s, r;
double res[MAX][MAX];

int main() {
	scanf("%d %d", &s, &r);
	memset(res, 0, sizeof res);
	for (i = 1; i < MAX; i++) res[0][i] = 1;
	for (i = 1; i <= s; i++) {
		for (j = 1; j <= r; j++)
		{
			res[i][j] = 2 * i * j * res[i][j - 1];
			if (i > 1) res[i][j] += i * (i - 1) * res[i - 2][j];
			res[i][j] /= (i + j) * (i + j - 1) - j * (j - 1);
		}
	}
	printf("%.11lf\n", res[s][r]);
	return 0;
}
