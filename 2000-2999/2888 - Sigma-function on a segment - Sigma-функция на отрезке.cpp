#include <iostream>

using namespace std;

#define MAX 5000001
#define LMAX 350001

int i, l, r, cnt, lp[MAX], primes[LMAX];
long s[MAX];

void LinearEratosfen()
{
	int i, j, x;
	long d;
	s[1] = 1; cnt = 0;
	for (i = 2; i < MAX; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			primes[cnt++] = i;
		}
		for (j = 0; j < cnt && primes[j] <= lp[i] && i * primes[j] < MAX; j++) lp[i * primes[j]] = primes[j];
		if (lp[i] == i) s[i] = i + 1;
		else
		{
			x = i; d = lp[i];
			while (lp[x] == lp[i])
			{
				x /= lp[i];
				d *= lp[i];
			}
			s[i] = s[x] * (d - 1) / (lp[i] - 1);
		}
	}
}

int main() {
	//Строим массив суммы делителей s(n) и в нем же вычисляем сумму на его префиксах.
	LinearEratosfen();
	for (i = 1; i < MAX; i++) s[i] += s[i - 1];
	while (scanf("%d %d", &l, &r) == 2) printf("%ld\n", s[r] - s[l - 1]);
	return 0;
}
