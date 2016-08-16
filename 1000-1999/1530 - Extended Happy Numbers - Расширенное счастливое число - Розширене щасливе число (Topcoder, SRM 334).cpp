#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 3200000

int a, b, k, ptr, powk[10], f[MAX];
long res;

//Функция sum вычисляет значение Sk(n), равное сумме k - ых степеней всех его цифр.
int sum(int n)
{
	int s;
	for (s = 0; n; n /= 10) s += powk[n % 10];
	return s;
}

int g(int n)
{
	//Если значение f[n] уже вычислено, то возвращаем его.
	if (f[n] > 0) return f[n];

	//При первом проходе по числам a0, …, as, …, at = as устанавливаем f[ai] = -1.
	if (f[n] == 0) f[n] = -1;
	else
		//Сюда попадаем, когда дойдем до as второй раз(часть пути от a0 до as и полный круг от as до as).
		if (f[n] == -1) f[n] = n;
	return f[n] = min(n, g(sum(n)));
}

//Функция calcTheSum вычисляет сумму счастья всех чисел от a до b включительно по отношению к k.
long calcTheSum(int a, int b, int k)
{
	int i, j, s;
	long res = 0;
	for (i = 0; i < 10; i++)
	{
		for (s = 1, j = 0; j < k; j++) s *= i;
		powk[i] = s;
	}
	for (i = a; i <= b; i++) res += g(i);
	return res;
}

int main() {
	while (scanf("%d %d %d", &a, &b, &k) == 3)
	{
		memset(f, 0, sizeof f);
		res = calcTheSum(a, b, k);
		printf("%ld\n", res);
	}
	return 0;
}
