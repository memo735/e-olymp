#include <iostream>

using namespace std;

long L, U, dp[10][11];

//Функция info(x, *len, *FirstDigit, *Rest) по входному значению x
//возвращает количество знаков в числе len, первую цифру числа FirstDigit
//и число Rest, полученное зачеркиванием первой цифры в числе x.
void info(int x, int *len, int *FirstDigit, int *Rest)
{
	int pow10 = *len = 1; *Rest = 0;
	while (x > 9)
	{
		(*len)++;
		*Rest = *Rest + x % 10 * pow10;
		x /= 10; pow10 *= 10;
	}
	*FirstDigit = x;
}

//Функция f(x) вычисляет сумму цифр всех чисел от 0 до x.
long f(int x)
{
	int i, len, FirstDigit, Rest;
	long res;
	if (x <= 0) return 0;
	info(x, &len, &FirstDigit, &Rest);
	for (res = i = 0; i < FirstDigit; i++) res += dp[i][len];
	return res + FirstDigit * (Rest + 1) + f(Rest);
}

//Функция getSum(L, U) возвращает сумму цифр всех чисел от L до U.
long getSum(int low, int up)
{
	int i, j, k;

	//Заполняем ячейки массива dp. Значение dp[i][j] равно сумме
	//цифр всех j - значных чисел, первая цифра которых равна i.
	for (i = 0; i < 10; i++) dp[i][0] = 0;
	for (k = j = 1; j < 11; j++)
	{
		dp[0][j] = 0;
		for (i = 0; i < 10; i++) dp[0][j] += dp[i][j - 1];
		for (i = 0; i < 10; i++) dp[i][j] = dp[0][j] + k * i;
		k *= 10;
	}
	return f(up) - f(low - 1);
}

int main() {
	while (scanf("%d %d", &L, &U) == 2) printf("%ld\n", getSum(L, U));
	return 0;
}
