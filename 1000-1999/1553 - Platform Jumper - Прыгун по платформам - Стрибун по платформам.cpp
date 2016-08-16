#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 50

int n, v, g;

struct pos
{
	long x, y, coins;
} c[MAX];

//Функция сортировки - платформы сортируются по возрастанию y - координат.
int f(pos a, pos b) { return a.y < b.y; }

long sqr(long x) { return x*x; }

//Начиная с последней платформы (наивысшей, которая имеет наибольшую y - координату), вычисляем значения ячеек opt[i].
int maxCoins(int v, int g)
{
	int i, j, res = 0;
	long opt[MAX];
	for (i = n - 1; i >= 0; i--)
	{
		//Если мы начинаем сбор монет с i - ой платформы и в ней же сбор заканчиваем, то положим opt[i] = c[i].coins.
		opt[i] = c[i].coins;
		for (j = i + 1; j < n; j++)
			//Если с j - ой платформы можно прыгнуть на i - ую платформу(i < j), и при этом сумма
			//opt[j] + c[i].coins будет больше opt[i], то пересчитываем значение opt[i].
			if (opt[j] + c[i].coins > opt[i] && g * sqr(c[i].x - c[j].x) <= 2 * sqr(v) * (c[j].y - c[i].y)) opt[i] = opt[j] + c[i].coins;
		if (opt[i] > res) res = opt[i];
	}
	return res;
}

int main() {
	//После считывания входнх данных сортируем платформы по
	//возрастанию их ординат.Вычисляем и выводим результат.
	while (scanf("%d %d %d", &n, &v, &g) == 3)
	{
		for (int i = 0; i < n; i++) scanf("%ld %ld %ld", &c[i].x, &c[i].y, &c[i].coins);
		sort(c, c + n, f);
		int res = maxCoins(v, g);
		printf("%d\n", res);
	}
	return 0;
}
