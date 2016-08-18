#include <iostream>
#include <string.h>

using namespace std;

long a, i, n, res, Bi, Mi, ai[100], c[100];
char ch[1];

void gcdext(long a, long b, long *d, long *x, long *y)
{
	long s;
	if (b == 0)
	{
		*d = a; *x = 1; *y = 0;
		return;
	}
	gcdext(b, a % b, d, x, y);
	s = *y;
	*y = *x - (a / b) * (*y);
	*x = s;
}

//Функция inv вычисляет  a^(-1) mod p. Если ax + py = g, то ax mod p = g mod p.
//Если a и p взаимно простые, то g = НОД(a, p) = 1 и последнее равенство примет
//вид ax mod p = 1, откуда x = a - 1mod p.Значение x должно принадлежать интервалу от 0 до p – 1.
long inv(long a, long p)
{
	long g, x, y;
	gcdext(a, p, &g, &x, &y);
	if (x < 0) x = p + x;
	return x;
}

//Рассмотрим дополнительные функции.Функция digit преобразовывает символ в цифру.
long digit(char c)
{
	if (c >= 'A') return c - 'A' + 10;
	return c - '0';
}

//Функция ToDecimal преобразовывает число в системе счисления base, заданное в строке s, в десятичное число.
long ToDecimal(char *s, long base)
{
	long i, res = 0;
	for (i = 0; i < strlen(s); i++) res = res * base + digit(s[i]);
	return res;
}

int main() {
	//Считываем входные данные, вычисляем произведение модулей в переменной a.
	scanf("%lld", &n);
	for (a = 1, i = 0; i < n; i++) scanf("%lld", &ai[i]), a *= ai[i];

	//В массив c заносим последние буквы сообщений, преобразовывая их в числовое значение.
	for (i = 0; i < n; i++) scanf("%s", ch), c[i] = ToDecimal(ch, ai[i]);

	//При помощи алгоритма Гаусса находим минимальное число, которое мог передать Штирлиц.
	for (res = i = 0; i < n; i++)
	{
		Bi = a / ai[i];
		Mi = Bi % ai[i];
		Mi = inv(Bi, ai[i]);
		res = (res + c[i] * Bi * Mi) % a;
	}
	printf("%ld\n", res);
	return 0;
}
