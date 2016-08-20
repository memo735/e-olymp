#include <iostream>

using namespace std;

#define MAX 1000001

int i, j, n, m, l, r, d, Fenwick[MAX];
char command;

int Summa0_i(int k)
{
	int result = 0;
	for (; k >= 0; k = (k & (k + 1)) - 1)
		result += Fenwick[k];
	return result;
}

//Изменение элемента : bi = bi + delta.
void IncElement(int k, int delta)
{
	for (; k < n; k = k | k + 1) Fenwick[k] += delta;
}

int main() {
	//Моделируем выполнение запросов.
	scanf("%d %d\n", &n, &m);
	for (j = 0; j < m; j++)
	{
		scanf("%c", &command);
		if (command == 'A')
		{
			scanf("%d %d %d\n", &l, &r, &d);
			IncElement(l, d);
			IncElement(r + 1, -d);
		}
		else
		{
			scanf("%d\n", &i);
			printf("%d\n", Summa0_i(i));
		}
	}
	return 0;
}
