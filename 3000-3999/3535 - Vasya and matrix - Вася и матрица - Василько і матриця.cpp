#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 301

int i, j, n, m, l, r, w, mid, answer, a[MAX][MAX];
long k, dp[MAX][MAX];

int f(int w, int h)
{
	int i, j;
	for (i = 1; i + w - 1 <= n; i++)
		for (j = 1; j + h - 1 <= m; j++)
			if (dp[i + w - 1][j + h - 1] - dp[i + w - 1][j - 1] -
				dp[i - 1][j + h - 1] + dp[i - 1][j - 1] <= k) return 1;
	return 0;
}

int main() {
	//Читаем входную матрицу.
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);

	//Переcчитаем матрицу dp.
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];

	//Перебираем ширину подматрицы w.
	answer = 0;
	for (w = 1; w <= n; w++)
	{
		//Длину подматрицы перебираем бинарным поиском на интервале [l; r].
		l = 1; r = m;
		while (l < r)
		{
			mid = (l + r) / 2;
			//Для подматрицы размера w * mid рассматриваем все возможные левые верхние
			//позиции (i, j). Если существует такое ее положение, что сумма чисел в ней
			//не больше k, то пересчитываем результирующую площадь answer.
			if (f(w, mid))
			{
				answer = max(answer, w * mid);
				l = mid + 1;
			}
			else r = mid;
		}
		mid = (l + r) / 2;
		if (f(w, mid)) answer = max(answer, w * mid);
	}
	printf("%d\n", answer);
	return 0;
}
