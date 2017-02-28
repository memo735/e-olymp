#include <iostream>

using namespace std;

long s[100001];

int main() {
	int a, b, i, n, q, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d", &n, &q);
		scanf("%ld", &s[1]);
		for (i = 2; i <= n; i++)
		{
			scanf("%ld", &s[i]);
			s[i] += s[i - 1];
		}
		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &a, &b);
			printf("%ld\n", s[b + 1] - s[a]);
		}
		if (tests > 0) printf("\n");
	}
	return 0;
}
