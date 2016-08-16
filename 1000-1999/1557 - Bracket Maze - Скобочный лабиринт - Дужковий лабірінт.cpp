#include <iostream>
#include <string.h>

using namespace std;

#define MAX 1000000000

char maze[4000], m[15][15][15];
int n, res, val[15][15][15][20];

//Функция go(i, j, k, x) вычисляет значение val[i][j][k][x].
//Если на каком - то этапе вычислений текущее количество путей temp
//станет больше MAX = 1000000000, то temp присваиваем значение MAX + 1.
//В дальнейшем это будет означать, что ответом на текущий тест будет - 1.
int go(int i, int j, int k, int x)
{
	int &temp = val[i][j][k][x];
	if (temp != -1) return temp;
	if (i >= n || j >= n || k >= n) return 0;
	if (m[i][j][k] == '(') x++;
	if (m[i][j][k] == ')') x--;
	if (x < 0) return 0;
	if (i == n - 1 && j == n - 1 && k == n - 1) return x == 0;
	temp = go(i + 1, j, k, x); if (temp > MAX) return temp = MAX + 1;
	temp += go(i, j + 1, k, x); if (temp > MAX) return temp = MAX + 1;
	temp += go(i, j, k + 1, x); if (temp > MAX) return temp = MAX + 1;
	return temp;
}

//Информацию о лабиринте переносим из строки maze в трехмерный массив m.
//Инициализируем ячейки массива val значениями - 1. Возвращаем искомое
//количество путей, которое будет записано в val[0][0][0][0].
//Его вычисление достигается вызовом go(0, 0, 0, 0).
int properPaths()
{
	int i, j, k, ptr, res;
	for (ptr = i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++) m[i][j][k] = maze[ptr++];

	memset(val, -1, sizeof val);
	res = go(0, 0, 0, 0);
	return res > MAX ? -1 : res;
}

int main() {
	while (scanf("%d %s", &n, &maze) == 2) printf("%d\n", properPaths());
	return 0;
}
