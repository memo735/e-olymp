#include <iostream>

using namespace std;

int i, n, k, val, Min, Max, sum[100001];

int main() {
	scanf("%d %d", &n, &k);
	//Вычисляем частичные суммы измерений температур.
	sum[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val);
		sum[i] = sum[i - 1] + val;
	}
	//Находим минимальное и максимальное значение среди всех сумм с k слагаемыми.
	Min = 1e9; Max = -1e9;
	for (i = k; i <= n; i++)
	{
		if (sum[i] - sum[i - k] < Min) Min = sum[i] - sum[i - k];
		if (sum[i] - sum[i - k] > Max) Max = sum[i] - sum[i - k];
	}
	printf("%.0lf\n%.0lf\n", 1.0*Min / k, 1.0*Max / k);
	return 0;
}
