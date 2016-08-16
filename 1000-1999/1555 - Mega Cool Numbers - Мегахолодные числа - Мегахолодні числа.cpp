#include <iostream>
#include <string.h>

using namespace std;

#define MOD 1000000007

int n, a, res, f[1000][10][10][10];

//Функция count возвращает количество мегахолодных чисел степени а, которые содержат в точности n цифр.
int count(int n, int a)
{
	int i, pow, last, diff, d, res;
	if (a > 9) return 0;
	memset(f, 0, sizeof f);
	for (d = 1; d <= 9; d++) f[1][1][9][d] = 1;
	for (i = 1; i < n; i++) {
		for (pow = 1; pow <= 9; pow++)
			for (last = 1; last <= 9; last++)
			{
				for (d = last; d <= 9; d++)
				{
					f[i + 1][pow][d - last][d] += f[i][pow][9][last];
					f[i + 1][pow][d - last][d] %= MOD;
				}
				for (diff = 0; diff <= 8; diff++)
					for (d = last; d <= 9; d++)
						if (d - last == diff)
						{
							f[i + 1][pow][diff][d] += f[i][pow][diff][last];
							f[i + 1][pow][diff][d] %= MOD;
						}
						else
							if (pow < 9)
							{
								f[i + 1][pow + 1][9][d] += f[i][pow][diff][last];
								f[i + 1][pow + 1][9][d] %= MOD;
							}
			}
	}
	res = 0;
	for (last = 1; last <= 9; last++)
		for (diff = 0; diff <= 9; diff++)
			res = (res + f[n][a][diff][last]) % MOD;
	return res;
}

int main() {
	while (scanf("%d %d", &n, &a) == 2) printf("%d\n", count(n, a));
	return 0;
}
