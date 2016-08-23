#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10001

int i, n, l, dist[MAX];
double res;

double max(double x, double y)
{
	return x > y ? x : y;
}

int main() {
	scanf("%d %d", &l, &n);
	for (i = 1; i <= n; i++) scanf("%d", &dist[i]);

	//Отсортируем входные позиции бензоколонок dist[1], …, dist[n].
	sort(dist + 1, dist + n + 1);

	//Ищем наименьшее расстояние между соседними бензоколонками с учетом того, что они расположены по кругу.
	//Расстояние между первой и последней бензоколонкой, являющимися соседними, равно l – dist[n] + dist[1].
	//Далее при вычислении минимума учитываются разности dist[2] – dist[1], …, dist[n] – dist[n – 1].
	res = l - dist[n] + dist[1];
	for (i = 1; i < n; i++) res = max(res, dist[i + 1] - dist[i]);

	//Выводим найденный ответ – половину наименьшего расстояния между соседними бензоколонками.
	printf("%.1lf\n", res / 2.0);
	return 0;
}
