#include <iostream>
#include <string.h>

using namespace std;

int N, M, h[5], f[6][25615];

int F(int n, int mask)
{
	if (n == 0) return 1;
	const int m = mask / 41;
	if (f[n][m] != -1) return f[n][m];
	f[n][m] = 0;

	//Перебираем все подмаски sub_mask маски mask. Поскольку 
	//возможны hi = 0, то следует обрабатывать и нулевые подмаски.
	for (int sub_mask = mask; ; sub_mask = (sub_mask - 1) & mask)
	{
		if (sub_mask % 41 == h[N - n]) f[n][m] += F(n - 1, sub_mask);
		if (sub_mask == 0) break;
	}
	return f[n][m];
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &h[i]);
	memset(f, -1, sizeof f);
	printf("%d\n", F(N, (1 << M) - 1));
	return 0;
}
