#include <iostream>
#include <algorithm>

using namespace std;

int n, m[1001];

//Функция go(n, visible) возвращает оптимальное время, за которое могут пересечь реку n людей.
//Переменная visible = 1, если следует выводить на экран саму стратегию перехода(visible = 0 иначе).
int go(int n, int visible)
{
	int First, Second, Best;
	//Случай пересечения реки одним человеком
	if (n == 1)
	{
		if (visible) printf("%d\n", m[0]);
		return m[0];
	}
	//Случай пересечения реки двумя людьми
	if (n == 2)
	{
		if (visible) printf("%d %d\n", m[0], m[1]);
		return m[1];
	}
	//Случай пересечения реки тремя людьми
	if (n == 3)
	{
		if (visible)
		{
			printf("%d %d\n", m[0], m[1]);
			printf("%d\n", m[0]);
			printf("%d %d\n", m[0], m[2]);
		}
		return m[0] + m[1] + m[2];
	}
	//Вычисляем оптимальное время First и Second, которое
	//получается при использовании двух выше описанных стратегий.
	First = m[0] + 2 * m[1] + m[n - 1];
	Second = 2 * m[0] + m[n - 2] + m[n - 1];
	if (First < Second) Best = First;
	else Best = Second;
	if (visible)
	{
		if (Best == First)
		{
			printf("%d %d\n", m[0], m[1]);
			printf("%d\n", m[0]);
			printf("%d %d\n", m[n - 2], m[n - 1]);
			printf("%d\n", m[1]);
		}
		else
		{
			printf("%d %d\n", m[0], m[n - 2]);
			printf("%d\n", m[0]);
			printf("%d %d\n", m[0], m[n - 1]);
			printf("%d\n", m[0]);
		}
	}
	//Рекурсивно вычисляем оптимальную стратегию для оставшихся n – 2 людей.
	return Best + go(n - 2, visible);
}

int main() {
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++) scanf("%d", &m[i]);

		//Сортируем время пересечения реки людьми по возрастанию. Запускаем функцию go с параметром
		//visible = 0, которая возвращает оптимальное время пересечения реки. Выводим его, после чего
		//снова запускаем функцию go с параметром visible = 1, которая печатает последовательность
		//переходов. Если текущий тест не последний, то выводим пустую строку.
		sort(m, m + n);
		int res = go(n, 0);
		printf("%d\n", res);
		res = go(n, 1);
	}
	return 0;
}
