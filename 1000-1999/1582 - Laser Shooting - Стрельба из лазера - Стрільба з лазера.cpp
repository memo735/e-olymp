#include <iostream>
#include <algorithm>

using namespace std;

#define PI acos(-1.0)

int i, n, x[51], yy1[51], yy2[51];

//Функция numberOfHits возвращает искомое ожидаемое количество
//целей, которое может быть поражено одним выстрелом.
double numberOfHits()
{
	double a1, a2, res = 0.0;
	for (i = 0; i < n; i++)
	{
		a1 = atan(1.0 * yy1[i] / x[i]);
		a2 = atan(1.0 * yy2[i] / x[i]);
		res += fabs(a1 - a2) / PI;
	}
	return res;
}

int main() {
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++) scanf("%d", &x[i]);
		for (i = 0; i < n; i++) scanf("%d", &yy1[i]);
		for (i = 0; i < n; i++) scanf("%d", &yy2[i]);
		printf("%.4lf\n", numberOfHits());
	}
	return 0;
}
