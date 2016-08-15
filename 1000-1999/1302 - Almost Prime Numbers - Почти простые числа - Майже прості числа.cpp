#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 1000001
char primes[MAX];
long l, h, ptr, m[MAX];

void gen_primes()
{
	int i, j;
	for (i = 0; i < MAX; i++) primes[i] = 1;
	for (i = 2; i <= (int)sqrt(1.0*MAX); i++)
		if (primes[i])
			for (j = i * i; j < MAX; j += i) primes[j] = 0;
}

int main() {
	gen_primes();
	//Для каждого простого числа i заносим в массив m числа i2, i3, i4, …
	//пока очередная степень не станет больше 10^12. Переменная ptr содержит
	//количество почти простых чисел, занесенных в массив m. Поскольку почти
	//простые числа ограничены значением 10^12, то работать следует с 64 битовыми целыми числами.
	for (int i = 2; i < MAX; i++)
		if (primes[i])
		{
			long temp = 1L * i*i;
			while (temp < 1L * MAX*MAX)
			{
				m[ptr++] = temp;
				temp *= i;
			}
		}

	//Сортируем массив m, используя STL :
	sort(m, m + ptr);

	//Читаем количество входных тестов tests и для каждого интервала[l, h] вычисляем
	//и выводим значение f(l, h) = f(1, h) – f(1, l – 1) за время O(log2 ptr).
	int tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%ld %ld", &l, &h);
		printf("%d\n", (int)(upper_bound(m, m + ptr, h) - upper_bound(m, m + ptr, l - 1)));
	}
	return 0;
}
