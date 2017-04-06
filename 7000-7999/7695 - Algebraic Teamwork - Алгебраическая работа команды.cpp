#include <iostream>

using namespace std;

#define MOD 1000000007
#define MAX 100001
long f[MAX];

int main() {
	int n, tests;
	f[0] = 1;
	for (int i = 1; i < MAX; i++) f[i] = f[i - 1] * i % MOD;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		printf("%ld\n", f[n] - 1);
	}
	return 0;
}
