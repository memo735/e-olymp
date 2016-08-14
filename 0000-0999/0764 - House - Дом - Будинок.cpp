#include <iostream>
#include <string.h>

using namespace std;

#define MAX 5001

int a, b, i, j, k, m, n, x, y, mas[MAX][MAX], res;

int main() {

	scanf("%d %d %d %d %d", &m, &n, &a, &b, &k);
	memset(mas, 0, sizeof mas);
	for (res = i = 0; i < k; i++)
	{
		scanf("%d %d", &x, &y);
		mas[x][y] = 1;
	}

	//Пересчитаем ячейки массива так, чтобы mas[i][j] содержало
	//количество радиоактивных ячеек в прямоугольнике(0, 0)-(i, j).
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++) mas[i][j] = mas[i][j] + mas[i - 1][j] + mas[i][j - 1] - mas[i - 1][j - 1];

	//Перебираем все возможные левые верхние углы дома(i, j), и проверяем,
	//содержится ли хоть одна радиоактивная клетка на месте дома.
	//Если ответ отрицательный, то на указанном месте можно построить дом.
	//В этом случае увеличиваем значение переменной res на 1.
	for (i = 1; i <= m - a + 1; i++)
		for (j = 1; j <= n - b + 1; j++)
			if (mas[i + a - 1][j + b - 1] + mas[i - 1][j - 1] - mas[i - 1][j + b - 1] - mas[i + a - 1][j - 1] == 0) res++;

	printf("%d\n", res);
	return 0;
}
