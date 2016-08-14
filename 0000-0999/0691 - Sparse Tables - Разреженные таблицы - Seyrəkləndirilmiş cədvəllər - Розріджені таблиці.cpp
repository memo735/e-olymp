#include <iostream>
#include <math.h>

using namespace std;
#define MAX 100001
#define LOGMAX 17

int n, m, u, v, u1, v1, ans, a[MAX], mas[MAX][LOGMAX];

//Если u > v, то функция check меняет их местами.
void check(int &u, int &v)
{
	if (u > v) swap(u,v);
}

void RMQ_nlogn()
{
	for (int i = 1; i <= n; i++) mas[i][0] = i;
	for (int j = 1; 1 << j <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			if (a[mas[i][j - 1]] < a[mas[i + (1 << j - 1)][j - 1]]) mas[i][j] = mas[i][j - 1];
			else mas[i][j] = mas[i + (1 << j - 1)][j - 1];
}

//Функция q совершает запрос RMQA(i, j) и возвращает индекс с наименьшим элементом (Range Minimum Query) в подмассиве a[i…j].
int q(int i, int j)
{
	int k = (int)(log(j - i + 1.0) / log(2.0));
	int res = mas[i][k];
	if (a[mas[j - (1 << k) + 1][k]] < a[res]) res = mas[j - (1 << k) + 1][k];
	return res;
}

int main() {

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &a[1], &u, &v);
	for (int i = 2; i <= n; i++) a[i] = (23 * a[i - 1] + 21563) % 16714589;

	//Строим массив m, в котором m[i][j] хранит индекс наименьшего элемента на промежутке (i, …, i + 2j – 1).
	//То есть m[i][j] содержит индекс минимального элемента в блоке длины 2j, начинающегося с позиции i.
	RMQ_nlogn();

	for (int i = 1; i <= m; i++)
	{
		u1 = u; v1 = v; check(u1, v1);

		//Запрос q(u1, v1) возвращает индекс наименьшего элемента на отрезке a[u1] … a[v1].
		ans = a[q(u1, v1)];
		if (i < m)
		{
			u = (17 * u + 751 + ans + 2 * i) % n + 1;
			v = (13 * v + 593 + ans + 5 * i) % n + 1;
		}
	}
	printf("%d %d %d\n", u, v, ans);
	return 0;
}
