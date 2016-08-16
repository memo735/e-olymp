#include <iostream>
#include <math.h>

using namespace std;

#define MAX 50001

int n, f[MAX], res[MAX];

int fi(int n)
{
	int i, result = n;
	for (i = 2; i <= sqrt(n);i++)
	{
		if (n % i == 0) result -= result / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) result -= result / n;
	return result;
}

int main() {
	f[1] = 0;
	for (int i = 2; i < MAX; i++) f[i] = fi(i);

	//Полагаем res[1] = 1 и рекурсивно пересчитываем значения res[i].
	res[1] = 1;
	for (int i = 2; i < MAX; i++) res[i] = res[i - 1] + 2 * f[i];
	while (scanf("%d", &n), n) printf("%d\n", res[n]);
	return 0;
}
