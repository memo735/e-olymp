#include <iostream>

using namespace std;

#define MAX 1200000

int n, ptr, tests, nom[MAX], denom[MAX];
bool flag;

//Генерируем все дроби со знаменателем, не большим n, в возрастающем
//порядке и заносим их числители и знаменатели в массивы nom и denom.
void farrey(int a1, int b1, int a2, int b2, int m)
{
	if (m < b1 + b2) return;
	farrey(a1, b1, a1 + a2, b1 + b2, m);
	nom[ptr] = a1 + a2;
	denom[ptr++] = b1 + b2;
	farrey(a1 + a2, b1 + b2, a2, b2, m);
}

int main() {
	scanf("%d", &tests);
	while (tests--)
	{
		//Переменная flag = 1 до тех пор пока не выведется первая дробь в строке
		//для заданного n. Дробь выводится только если ее знаменатель не больше n.
		scanf("%d", &n); flag = 1;

		//Генерируем правильные несократимые дроби в порядке возрастания при помощи функции farrey.
		ptr = 0; farrey(0, 1, 1, 1, n);
		for (int i = 0; i < ptr; i++)
		{
			if (denom[i] <= n)
				if (flag)
				{
					printf("%d/%d", nom[i], denom[i]);
					flag = 0;
				}
				else printf(", %d/%d", nom[i], denom[i]);
		}
		printf("\n");
	}
	return 0;
}
