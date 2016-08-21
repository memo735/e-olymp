#include <iostream>
#include <math.h>
#include <string.h>


using namespace std;

#define MAX 5001

int i, j, n, v, to, x[MAX], y[MAX], used[MAX], min_e[MAX], end_e[MAX];

int sqr(int x) { return x*x; }

int mesafe(int i, int j) { return sqr(x[j] - x[i]) + sqr(y[j] - y[i]); }

int main() {
	//Читаем координаты городов.
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
	memset(min_e, 0x3F, sizeof min_e);
	memset(end_e, -1, sizeof end_e);
	memset(used, 0, sizeof used);
	double dist = min_e[1] = 0;

	//Ищем вершину v с минимальным значением min_e[v] среди еще не
	//включенных в минимальный остов вершин(для которых used[v] = 0).
	for (i = 0; i < n; i++)
	{
		v = -1;
		for (j = 0; j < n; j++)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v])) v = j;

		//Включаем вершину v в остов. Добавляем в остов ребро (v, end_e[v]).
		used[v] = 1;
		if (end_e[v] != -1) dist += sqrt(mesafe(v, end_e[v]));

		//Пересчитываем метки для ребер, исходящих из v.
		for (to = 0; to < n; to++)
		{
			int dV_TO = mesafe(v, to);
			if (!used[to] && dV_TO < min_e[to])
			{
				min_e[to] = dV_TO;
				end_e[to] = v;
			}
		}
	}
	printf("%.6lf\n", dist);
	return 0;
}
