#include <iostream>
#include <string.h>

using namespace std;

#define MAX 2001
int i, n, m, x[MAX], y[MAX], w[MAX], d[MAX];

int Bellman_Ford()
{
	//Стартовой вершиной объявляем нулевую (нашу солнечную систему).
	memset(d, 0x3F, sizeof d);
	d[0] = 0;

	//Совершаем релаксацию всех ребер | V(G) | – 1 раз.
	for (int i = 0; i < n; i++)
		//Проходим по всем m ребрам и релаксируем их. Ребро(u, v) релаксируем,
		//если значение d[u] не равно плюс бесконечности.
		for (int j = 0; j < m; j++)
			if (d[x[j]] < 0x3F3F3F3F && d[y[j]] > d[x[j]] + w[j]) d[y[j]] = d[x[j]] + w[j];

	//Проверяем, существует ли ребро, которое релаксирует.
	//Если да – то в графе существует цикл отрицательной длины.
	//Иначе такого цикла не существует.
	for (int i = 0; i < m; i++)
		if (d[y[i]] > d[x[i]] + w[i]) return 0;
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d %d %d", &x[i], &y[i], &w[i]);
	if (Bellman_Ford()) printf("not ");
	printf("possible\n");
	return 0;
}
