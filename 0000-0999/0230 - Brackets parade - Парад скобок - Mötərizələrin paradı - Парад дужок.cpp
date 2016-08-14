#include <iostream>

using namespace std;

#define MD 1000000007
#define MAX 1001
long k[MAX], cat[MAX], cnk[MAX][MAX];

//Функция c вычисляет значение биномиального коэффициента cnk и запоминает его в ячейке cnk[n][k].
long c(int n, int k)
{
	//Если k = 0, то значение  равно 1.
	if (!k) return cnk[n][k] = 1;

	//Если cnk[n][k] > 0, то значение  было вычислено ранее. Следует его просто вернуть.
	if (cnk[n][k] > 0) return cnk[n][k];

	//Поскольку cnk[n][k] =cnk[n][n-k], то если при n – k < k вместо cnk[n][k] находить cnk[n][n-k],
	//то время вычисления биномиального коэффициента уменьшится.
	if (n - k < k) return c(n, n - k);

	//Для вычисления биномиального коэффициента используем рекуррентное соотношение
	//cnk[n][k]= cnk[n-1][k]+cnk[n-1][k-1]
	return cnk[n][k] = (c(n - 1, k) + c(n - 1, k - 1)) % MD;
}

int main() {
	//Основная часть программы. В массиве cat вычисляем числа Каталана исходя из рекуррентной формулы. 
	//Вычисления проводим по модулю MD = 1000000007.

	cat[0] = cat[1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		for (int j = 0; j < i; j++) cat[i] = (cat[i] + cat[j] * cat[i - j - 1]) % MD;
	}
	int i, n, m, s;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		for (s = 0, i = 1; i <= m; i++) scanf("%d", &k[i]), s += k[i];

		//Положим сначала результат res равным Cat(s).
		long res = cat[s];

		//Умножаем значение res на  для всех i от 1 до m.
		for (i = 1; i <= m; i++) res = res * c(s, k[i]) % MD, s -= k[i];
		printf("%ld\n", res);
	}
	return 0;
}
