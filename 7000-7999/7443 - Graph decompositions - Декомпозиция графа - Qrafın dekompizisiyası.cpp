#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MOD 1000000007L
#define MAX 1001
long c[MAX][MAX], in[MAX], out[MAX], fac[MAX];

//Пусть вершина имеет x входящих и y исходящих ребер.
//Тогда количество способов провести ее декомпозицию равно f(x, y).
long f(int x, int y)
{
	long ans = 0;
	for (int i = 0; i <= min(x, y); i++) ans = (ans + c[x][i] * c[y][i] % MOD * fac[i] % MOD) % MOD;
	return ans;
}

int main() {
	int i, n, m, x, y;
	scanf("%d %d", &n, &m);
	memset(c, 0, sizeof c);
	memset(in, 0, sizeof in);
	memset(out, 0, sizeof out);
	memset(fac, 0, sizeof fac);

	c[0][0] = 1;
	for (i = 0; i < MAX; i++) c[i][0] = 1;
	for (i = 1; i < MAX; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;

	fac[0] = 1;
	for (i = 1; i < MAX; i++) fac[i] = fac[i - 1] * i % MOD;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		out[x]++;
		in[y]++;
	}
	//Вычисляем произведение способов, которыми можно провести декомпозицию ребер в каждой вершине.
	long ans = 1;
	for (i = 1; i <= n; i++) ans = ans * f(in[i], out[i]) % MOD;
	printf("%ld\n", ans);
	return 0;
}
