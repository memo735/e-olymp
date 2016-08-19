#include <iostream>

using namespace std;

int i, j, n, m[101][101];

int main() {
	//Читаем входной граф.Если он содержит петлю (m[i][i] = 1 для некоторого значения i), то не является простым.
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			scanf("%d", &m[i][j]);
			if (i == j && m[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	//Проверяем матрицу на симметричность относительно главной диагонали.
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (m[i][j] != m[j][i])
			{
				printf("NO\n");
				return 0;
			}
	}
	printf("YES\n");
	return 0;
}
