#include <iostream>
#include <algorithm>

using namespace std;

int i, n, m, q, t, v, x, y, a[100001];

int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	int add = 0;
	//Последовательно обрабатываем m операций.Тип операции читаем в переменную t.
	for (i = 0; i < m; i++)
	{
		scanf("%d", &t);
		//Выполняем присвоение avi  = xi
		if (t == 1)
		{
			scanf("%d %d", &v, &x);
			a[v] = x - add;
		}
		else
			//Увеличиваем каждый элемент массива на yi.
			if (t == 2)
			{
				scanf("%d", &y);
				add += y;
			}
			else //Выводим qi - ый элемент массива.
			{
				scanf("%d", &q);
				printf("%d\n", a[q] + add);
			}
	}
	return 0;
}
