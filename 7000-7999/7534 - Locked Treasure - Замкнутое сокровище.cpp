#include <iostream>
#include <string.h>

using namespace std;

#define MAX 31

int main() {
	int i, k, m, tests, cnk[MAX][MAX];
	memset(cnk, 0, sizeof cnk);
	for (i = 0; i < MAX; i++) cnk[i][0] = 1;
	for (i = 1; i < MAX; i++)
		for (k = 1; k <= MAX; k++)
			cnk[i][k] = cnk[i - 1][k] + cnk[i - 1][k - 1];

	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d", &i, &m);
		printf("%d\n", cnk[i][m - 1]);
	}
	return 0;
}
