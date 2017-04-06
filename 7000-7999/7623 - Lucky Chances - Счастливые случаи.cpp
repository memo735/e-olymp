#include <iostream>
#include <string.h>

using namespace std;

int c, i, j, r, res, m[101][101], m1[101][101];

//Подсчитаем количество ячеек res, для которых левое направление будет выигрышным.
int check()
{
	int i, j, s, res = 0;
	for (i = 0; i < r; i++)
	{
		for (s = j = 0; j < c; j++)
			if (m[i][j] > s)
			{
				s = m[i][j];
				res++;
			}
	}
	return res;
}

void rotate()
{
	int i, j, s;
	memset(m1, 0, sizeof m1);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			m1[j][r - i - 1] = m[i][j];

	memcpy(m, m1, sizeof m);
	s = r; r = c; c = s;
}

int main() {
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) scanf("%d", &m[i][j]);

	//Прибавляем к res количество ячеек, для которых левое направление
	//будет выигрышным. После чего поворачиваем таблицу. Повторяем
	//4 раза (левое, нижнее, правое, верхнее направления).
	res = 0;
	for (i = 0; i < 4; i++)
	{
		res += check();
		rotate();
	}
	printf("%d\n", res);
	return 0;
}
