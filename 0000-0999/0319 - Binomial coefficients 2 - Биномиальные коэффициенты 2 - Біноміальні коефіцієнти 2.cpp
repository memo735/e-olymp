#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 100001
bool flag;
int primes[MAX], deg[MAX], pr[100];

void factor(int n, int flag)
{
	for (int i = 0; pr[i] <= (int)sqrt(1.0*n); i++)
		while (n % pr[i] == 0) n /= pr[i], deg[pr[i]] += flag;
	if (n > 1) deg[n] += flag;
}

//Решето Эратосфена. Строим массив primes, в котором primes[i] = 1, только если число i простое.
void gen_primes()
{
	int i, j;
	for (i = 0; i < MAX; i++) primes[i] = 1;
	primes[0] = primes[1] = 0;
	for (i = 2; i <= sqrt(1.0*MAX); i++)
		if (primes[i])
			for (j = i * i; j < MAX; j += i) primes[j] = 0;

	//Заносим в массив pr простые числа от 2 до sqrt(MAX).
	for (j = i = 0; i <= sqrt(1.0*MAX); i++) if (primes[i]) pr[j++] = i;

	//В конце массива ставим заглушку(число, квадрат которого строго больше MAX).
	pr[j] = MAX;
}

//Моделируем вычисление биномиального коэффициента. На самом деле раскладываем
//на множители все множители, стоящие в числителе и знаменателе дроби
void Cnk(int n, int k)
{
	int i;
	memset(deg, 0, sizeof deg);
	for (i = 1; i <= k; i++) factor(n - i + 1, 1), factor(i, -1);
}

int main() {
	gen_primes();
	int i, n, k, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d", &n, &k);
		if (k > n - k) k = n - k;
		if (n == 1 || !k)
		{
			printf("1\n");
			continue;
		}
		Cnk(n, k);

		//Выводим ответ. Если deg[i] ≠ 0, то простой множитель i входит в разложение Cnk(n,k) со степенью deg[i].
		for (flag = i = 0; i < MAX; i++) {
			if (deg[i])
			{
				if (flag) printf(" * ");
				printf("%d", i); flag = 1;
				if (deg[i] > 1) printf("^%d", deg[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
