#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, d, i, n, flag, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n); flag = 0;
		for (d = 2; d * d <= 2 * n; d++)
		{
			//Если 2n делится на d, то проверяем является ли a = 2n / d + 1 – d четным.
			if (2 * n % d == 0)
			{
				a = 2 * n / d + 1 - d;
				if (a % 2 == 0)
				{
					a /= 2;
					//В случае существования решения выводим ответ и устанавливаем flag = 1.
					//При этом если имеется несколько решений, то первым будет найдено
					//решение с наименьшим d(то есть с наименьшим количеством слагаемых).
					printf("%d = %d", n, a);
					for (i = 1; i < d; i++) printf(" + %d", a + i);
					printf("\n"); flag = 1;
					break;
				}
			}
		}
		if (flag == 0) printf("IMPOSSIBLE\n");
	}
	return 0;
}
