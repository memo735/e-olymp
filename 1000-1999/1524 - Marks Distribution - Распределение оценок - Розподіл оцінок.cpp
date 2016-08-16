#include <iostream>
#include <string.h>

using namespace std;

#define MAX 71
int i, j, n, t, p, tests, m[MAX][MAX];

int main() {
	//Проведем инициализацию, положив f(i, 1) = f(0, i) = 1 (0 < i < MAX).
	//Значения m[i, j] пересчитываем как сумму m[i, j – 1] и m[i – 1, j].
	//Находим значения всех ячеек массива m, совершая таким образом предвычисления.
	memset(m, 0, sizeof m);
	for (i = 0; i < MAX; i++) m[1][i] = m[i][0] = 1;
	for (i = 2; i < MAX; i++)
		for (j = 1; j < MAX; j++) m[i][j] = m[i][j - 1] + m[i - 1][j];

	//Для каждого теста вводим значения n, t, p.
	//Положим t = t – n * p.Выводим результат, хранящийся в ячейке m[n, t].
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d %d", &n, &t, &p);
		t -= n * p;
		printf("%d\n", m[n][t]);
	}
	return 0;
}
