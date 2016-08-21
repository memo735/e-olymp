#include <iostream>

using namespace std;

#define MAX 1000001

int d, f, i, j, n, q, t, value, Fenwick[MAX];
char c;

//Функция Summa0_i возвращает сумму элементов a0 + a1 + ... + ai.
int Summma0_i(int i)
{
	int result = 0;
	for (; i >= 0; i = (i & i + 1) - 1) result += Fenwick[i];
	return result;
}

//Изменение элемента : a[i] = a[i] + delta.
void IncElement(int i, int delta)
{
	for (; i < MAX; i = (i | i + 1)) Fenwick[i] += delta;
}

int main() {
	//Читаем входные данные.Заполняем дерево Фенвика.
	scanf("%d %d", &n, &q);
	for (i = 1; i <= n; i++) scanf("%d", &value), IncElement(i, value);
	scanf("\n");

	//Моделируем выполнение запросов.
	for (j = 0; j < q; j++)
	{
		scanf("%c ", &c);
		if (c == '+')
		{
			scanf("%d %d\n", &i, &d);
			IncElement(i, d);
		}
		else
		{
			scanf("%d %d\n", &f, &t);
			printf("%d\n", Summma0_i(t) - Summma0_i(f - 1));
		}
	}
	return 0;
}
