#include <iostream>

using namespace std;

#define MAX 110
#define INF 0x3F3F3F3F

int i, j, n, Max, diam, radius, g[MAX][MAX];

//Поиск кратчайших расстояний – алгоритм Флойда – Уоршела.
void floyd()
{
	int i, j, k;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			scanf("%d", &g[i][j]);
			if (g[i][j] < 0) g[i][j] = INF;
		}
	}
	floyd();
	//Для каждой i-ой вершины находим максимальное расстояние max от нее до остальных. Среди всех
	//таких максимумов находим минимум, равный радиусу графа.Максимум максимумов равен диаметру графа.
	diam = 0; radius = INF;
	for (i = 0; i < n; i++)
	{
		Max = 0;
		for (j = 0; j < n; j++) if (g[i][j] > Max) Max = g[i][j];
		if (Max > diam) diam = Max;
		if (Max < radius) radius = Max;
	}
	printf("%d\n%d\n", diam, radius);
	return 0;
}
