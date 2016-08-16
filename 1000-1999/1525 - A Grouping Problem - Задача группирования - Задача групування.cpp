#include <iostream>
#include <string.h>

using namespace std;

int main() {
	long n, m, num, res, d[1000];
	while (scanf("%lld %lld", &n, &m), n + m > 0)
	{
		memset(d, 0, sizeof d);
		scanf("%lld", &d[0]);

		//Вводим значение num = ai + 1 (1 < i < n) и пересчитываем значения F[ik], k = i, i – 1, …, 1
		//по выше приведенным рекуррентным формулам.Все вычисления проводим по модулю m.
		for (int i = 1; i < n; i++)
		{
			scanf("%lld", &num);
			d[i] = d[i - 1] * num % m;
			for (int j = i - 1; j > 0; j--) d[j] = (d[j - 1] * num + d[j]) % m;
			d[0] = (d[0] + num) % m;
		}
		//Находим максимальное значение среди элементов массива d и заносим его в переменную res.
		res = d[0];
		for (int i = 1; i < n; i++) if (d[i] > res) res = d[i];
		printf("%ld\n", res);
	}
	return 0;
}
