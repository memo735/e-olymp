#include <iostream>

using namespace std;

#define INF 100000000
#define MAX 101

int n, m[MAX][MAX], res[MAX][MAX];

//Алгоритм Флойда-Уоршела. Поскольку ребра графа имеют отрицательные веса, то аккуратно их обрабатываем :
//если на каком - то этапе обработки m[i][j] станет меньше - INF, то положим m[i][j] = -INF.
void floyd()
{
	int i, j, k;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if ((m[i][k] < INF) && (m[k][j] < INF))
				{
					if (m[i][k] + m[k][j] < m[i][j]) m[i][j] = m[i][k] + m[k][j];
					if (m[i][j] < -INF) m[i][j] = -INF;
				}
}

int main() {
	//На диагонали устанавливаем нули. Если между вершинами i и j нет ребра, то устанавливаем m[i][j] = INF.
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &m[i][j]);
			if (m[i][j] == 0 && i != j) m[i][j] = INF;
		}

	floyd();

	//Строим результирующую матрицу res. Если пути между вершинами i и j не существует,
	//то устанавливаем res[i][j] = 0. Иначе устанавливаем res[i][j] = 1, после чего ищем циклические пути.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (m[i][j] == INF) res[i][j] = 0;
			else
			{
				res[i][j] = 1;

				//Между вершинами i и j не существует кратчайшего пути, если для некоторой вершины k
				//существует путь из i в k и из k в j, а также существует цикл отрицательной длины,
				//начинающийся и заканчивающийся в вершине k(в ней m[k][k] < 0).
				for (int k = 0; k < n; k++)
					if (m[k][k] < 0 && m[i][k] < INF && m[k][j] < INF) res[i][k] = res[i][j] = res[k][j] = 2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", res[i][0]);
		for (int j = 1; j < n; j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
	return 0;
}
