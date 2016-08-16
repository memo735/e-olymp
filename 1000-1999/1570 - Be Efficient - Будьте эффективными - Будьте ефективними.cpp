#include <iostream>
#include <string.h>

using namespace std;

#define MAXN 10000
int a, b, c, m, n, res, tests, x[MAXN], s[MAXN], mod[MAXN];

int main() {
	scanf("%d", &tests);
	for (int t = 1; t <= tests; t++)
	{
		scanf("%d %d %d %d %d", &a, &b, &c, &m, &n);

		//Вычисляем элементы последовательности x[i] и сумм s[i].
		x[0] = a; s[0] = a % m;
		for (int i = 1; i < n; i++)
			x[i] = (x[i - 1] * b + c) % m + 1,
			s[i] = (s[i - 1] + x[i]) % m;

		//Вычисляем элементы mod[i], равные количеству элементов s[j], равных i.
		memset(mod, 0, sizeof mod);
		for (int i = 0; i < n; i++) mod[s[i]]++;

		//Поскольку s[–1] = 0, то следует увеличить mod[0] на 1. Находим результат по выше приведенной формуле и выводим его.
		mod[0]++; res = 0;
		for (int i = 0; i < m; i++) res += mod[i] * (mod[i] - 1) / 2;
		printf("Case %d: %d\n", t, res);
	}
	return 0;
}
