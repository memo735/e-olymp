#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int a, b, i, j, n, m, g[101][101];
	scanf("%d %d", &n, &m);
	memset(g, 0, sizeof g);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	//Выполняем побитовое AND для всех элементов матрицы, расположенных над главной диагональю.
	//Если все они равны 1, то по окончанию цикла переменная res будет содержать 1.
	int res = 1;
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++) res &= g[i][j];

	if (res == 1) puts("YES");
	else puts("NO");
	return 0;
}
