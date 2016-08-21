#include <iostream>

using namespace std;

#define MAX 10000001
#define LMAX 700000

int n, cnt, tests, lp[MAX] = { 0 }, primes[LMAX];
char mu[MAX] = { 0 };

//Линейный Эратосфен. lp[i] содержит наименьший простой делитель числа i.
void LinearEratosfen()
{
	int i, j;
	for (i = 2; i <= MAX; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			primes[cnt++] = i;
		}
		for (j = 0; j < cnt && primes[j] <= lp[i] && i * primes[j] <= MAX; j++)
			lp[i * primes[j]] = primes[j];
	}
}

//Вычисление функции Мебиуса используя массив lp.
void calc_Mobius()
{
	int i, q;
	mu[1] = 1;
	for (i = 2; i < MAX; i++)
	{
		q = i / lp[i];
		if (q % lp[i] != 0) mu[i] = -mu[q];
	}
	//В массиве lp вычисляем значение функции Мертенса (чтобы не
	//вводить новый линейный массив, таким образом сэкономив память).
	lp[1] = mu[1];
	for (i = 2; i < MAX; i++) lp[i] = lp[i - 1] + mu[i];
}

int main() {
	//Вычисляем функцию Мертенса для всех значений от 1 до 10^7.
	LinearEratosfen();
	calc_Mobius();
	//Читаем входные данные.Для каждого значения n выводим lp[n].
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		printf("%d\n", lp[n]);
	}
	return 0;
}
