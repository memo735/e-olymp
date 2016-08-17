#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define SIZE 1001

int main() {
	int i, j, n, m, x[SIZE], y[SIZE], mas[2][SIZE];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &x[i]);
	scanf("%d", &m);
	for (i = 1; i <= m; i++) scanf("%d", &y[i]);

	//Обнулим массив mas. Динамически вычисляем значения f(i, j). Изначально mas[0][j] содержит
	//значения f(0, j). Далее в mas[1][j] заносим значения f(1, j). Поскольку для вычисления
	//f(2, j) достаточно иметь значения двух предыдущих строк массива mas, то значения f(2, j)
	//можно сохранять в ячейках mas[0][j], значения f(3, j) – в ячейках mas[1][j] и так далее.
	memset(mas, 0, sizeof mas);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (x[i] == y[j]) mas[i % 2][j] = 1 + mas[(i + 1) % 2][j - 1];
			else mas[i % 2][j] = max(mas[(i + 1) % 2][j], mas[i % 2][j - 1]);

			printf("%d\n", mas[n % 2][m]);
			return 0;
}
