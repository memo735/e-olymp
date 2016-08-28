#include <iostream>

using namespace std;

#define MAX 1000001

int i, n, m, l, q, r, x, sum, cnt[MAX], coins[MAX];

int main() {
	//Читаем входные данные. Строим массив cnt.
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &l, &r);
		cnt[l]++; cnt[r + 1]--;
	}
	//В переменной sum подсчитываем частичные суммы массива cnt. i-ая частичная сумма
	//равна количеству монет в i-ой копилке. coins[i] равно количеству копилок с суммой i.
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += cnt[i];
		coins[sum]++;
	}
	//Пересчитаем частичные суммы для массива coins.
	for (i = MAX - 2; i >= 0; i--) coins[i] += coins[i + 1];

	//Читаем запросы и выводим ответы.
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &x);
		printf("%d\n", coins[x]);
	}
	return 0;
}
