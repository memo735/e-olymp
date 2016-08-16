#include <iostream>

using namespace std;

struct RatNumber
{
	long x, y;
} c, temp;

long gcd(long a, long b) {
	return b > 0 ? gcd(b, a%b) : a;
}

int digits(long x)
{
	int res = 0;
	while (x > 0)
	{
		x = x / 10;
		res++;
	}
	return res;
}

//Сложение рациональных чисел a и b. Возвращаемая сумма является несократимой дробью.
//Функция gcd вычисляет наибольший общий делитель.
struct RatNumber add(struct RatNumber a, struct RatNumber b)
{
	struct RatNumber res;
	res.x = a.x*b.y + a.y*b.x;
	res.y = a.y * b.y;
	long d = gcd(res.x, res.y);
	if (d) res.x /= d, res.y /= d;
	return res;
}

int main() {
	int i, n;
	while (scanf("%d", &n) == 1)
	{
		c.x = 0; c.y = 1; temp.x = 1;
		for (i = 1; i <= n; i++)
		{
			temp.y = i;
			c = add(c, temp);
		}
		c.x = n * c.x;
		long d = gcd(c.x, c.y);
		c.x /= d; c.y /= d;
		d = c.x / c.y;
		c.x -= d * c.y;

		//Переменная d содержит целую часть результата c. Если знаменатель результата равен 1,
		//то выводим только числитель.Иначе форматируем вывод ответа, как показано в условии задачи.
		//Функция digits находит количество знаков числа x.
		if (c.y > 1)
		{
			for (i = 0; i <= digits(d); i++) printf(" ");
			printf("%ld\n", c.x);
			printf("%ld ", d);
			for (i = 0; i < digits(c.y); i++) printf("-"); printf("\n");
			for (i = 0; i <= digits(d); i++) printf(" ");
			printf("%ld\n", c.y);
		}
		else printf("%ld\n", d);
	}
	return 0;
}
