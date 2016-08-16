#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 16

double best[1 << MAX];
int i, n, f[MAX];

//Функция area вычисляет площадь треугольника по формуле Герона.
double area(int a, int b, int c)
{
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

//Функция FindSol возвращает максимальную площадь, которую можно оградить
//при помощи оград, входящих в маску mask, треугольными формами.
double FindSol(int mask)
{
	if (best[mask] >= 0.0) return best[mask];
	best[mask] = 0;
	for (int i = 0; i < n - 2; i++)
		if (mask & 1 << i)
			for (int j = i + 1; j < n - 1; j++)
				if (mask & 1 << j)
					for (int k = j + 1; k < n; k++)
						if (mask & 1 << k && f[i] + f[j] > f[k])
							best[mask] = max(best[mask], area(f[i], f[j], f[k]) + FindSol(mask ^ 1 << i ^ 1 << j ^ 1 << k));
	return best[mask];
}

int main() {

	while (scanf("%d", &n) == 1)
	{
		memset(f, 0, sizeof f);
		for (i = 0; i < n; i++) scanf("%d", &f[i]);
		sort(f, f + n);
		for (i = 0; i < 1 << MAX; i++) best[i] = -1.0;
		printf("%.4lf\n", FindSol((1 << n) - 1));
	}
	return 0;
}
