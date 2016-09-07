#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100001

int i, n, Fenwick[MAX], a[MAX], pref[MAX];
long res;

//Вычисление суммы a[0] + a[1] + … + a[i].
int Summma0_i(int i)
{
	int result = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) result += Fenwick[i];
	return result;
}

//Увеличение элемента a[i] на единицу.
void IncElement(int i)
{
	for (; i < MAX; i = i | (i + 1)) Fenwick[i]++;
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);

	//Для каждого значения ai подсчитаем количество элементов, стоящих левее и строго больших ai.Это значение занесем в pref[i].
	for (i = 0; i < n; i++)
	{
		pref[i] = i - Summma0_i(a[i]);
		IncElement(a[i]);
	}
	//Двигаемся справа налево по массиву a.Вычисляем результат по приведенной в анализе формуле.
	memset(Fenwick, 0, sizeof Fenwick);
	for (i = n - 1; i > 0; i--)
	{
		res += 1L * pref[i] * Summma0_i(a[i] - 1);
		IncElement(a[i]);
	}
	printf("%ld\n", res);
	return 0;
}
