#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>


using namespace std;

#define MAX 200001

vector<int> graph[MAX];
int i, n, m, vaxt, v1, v2, v3, Vertices, used[MAX], d[MAX], up[MAX], ArtPoints[MAX];

//Поиск в глубину, в котором строятся массивы d и up и фиксируются точки сочленения.
//ArtPoints[v] устанавливаем в 1, если вершина v – точка сочленения. Иначе ArtPoints[v] равно 0.
void dfs(int v, int p = -1)
{
	used[v] = 1;
	d[v] = up[v] = vaxt++;
	int children = 0;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int to = graph[v][i];
		if (to == p)  continue;
		if (used[to]) up[v] = min(up[v], d[to]);
		else
		{
			dfs(to, v);
			up[v] = min(up[v], up[to]);
			if (up[to] >= d[v] && p != -1) ArtPoints[v] = 1;
			children++;
		}
	}
	if (p == -1 && children > 1) ArtPoints[v] = 1;
}

int main() {
	//Читаем входные данные. Строим граф.
	scanf("%d %d", &n, &m);
	Vertices = n + m;
	memset(used, 0, sizeof used);
	memset(d, 0, sizeof d);
	memset(up, 0, sizeof up);
	memset(ArtPoints, 0, sizeof ArtPoints);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		graph[n + i].push_back(v1); graph[v1].push_back(n + i);
		graph[n + i].push_back(v2); graph[v2].push_back(n + i);
		graph[n + i].push_back(v3); graph[v3].push_back(n + i);
	}
	//Запускаем поиск в глубину на графе, ищем все точки сочленения.
	for (i = vaxt = 1; i <= Vertices; i++) if (!used[i]) dfs(i);

	//Подсчитываем количество точек сочленения cntArtPoints.
	int cntArtPoints = 0;
	for (i = n + 1; i <= Vertices; i++) if (ArtPoints[i]) cntArtPoints++;
	printf("%d\n", cntArtPoints);

	//Выводим номера магнитных подушек, удаление которых невозможно без нарушения сообщения в городе
	int flag = 0;
	if (cntArtPoints)
	{
		for (i = n + 1; i <= Vertices; i++)
			if (ArtPoints[i])
			{
				if (flag) printf(" ");
				printf("%d", i - n);
				flag = 1;
			}
		printf("\n");
	}
	return 0;
}
