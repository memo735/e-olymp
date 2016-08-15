#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b > 0) return gcd(b, a % b);
	return a;
}

int main() {
	int n, t, h, low, Less, Greater, Height, coins[101];
	while (scanf("%d %d", &n, &t), n + t > 0)
	{
		for (int i = 0; i < n; i++) scanf("%d", &coins[i]);

		//Для каждой прочитанной желаемой высоты стола Height применяем описанный выше алгоритм.
		//Обозначим через Less максимум среди всевозможных low, а через  Greater – минимум среди
		//всевозможных more.Проинициализируем их.
		while (t--)
		{
			scanf("%d", &Height);
			Greater = 0x7FFFFFFF;
			Less = 0;

			//Перебираем все возможные четверки номиналов монет x1 < x2< x3 < x4
			//(номиналы монет хранятся соответственно в coins[x1], coins[x2], coins[x3], coins[x4]).
			for (int x1 = 0; x1 < n - 3; x1++) {
				for (int x2 = x1 + 1; x2 < n - 2; x2++)
					for (int x3 = x2 + 1; x3 < n - 1; x3++)
						for (int x4 = x3 + 1; x4 < n; x4++)
						{
							//Вычисляем НОК толщин монет g = НОК(coins[x1], coins[x2], coins[x3], coins[x4]).
							h = coins[x1] * coins[x2] / gcd(coins[x1], coins[x2]);
							h = h / gcd(h, coins[x3]) * coins[x3];
							h = h / gcd(h, coins[x4]) * coins[x4];

							//Для каждой четверки номиналов пересчитываем значения Less и Greater.
							low = Height / h * h;
							if (low > Less) Less = low;
							if (low != Height) low += h;
							if (low < Greater) Greater = low;
						}
			}
			printf("%d %d\n", Less, Greater);
		}
	}
	return 0;
}
