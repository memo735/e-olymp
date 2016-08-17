#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 50

int n, cap[MAX][MAX], res[MAX][MAX], used[MAX];
char s[MAX];

//Функция aug(x, t, CurFlow) находит пропускную способность дополняющего пути от вершины x до t,
//если известно, что пропускная способность дополняющего пути от начальной вершины до x равна CurFlow.
int aug(int x, int t, int CurFlow)
{
	if (x == t) return CurFlow;
	if (used[x]++) return 0;
	for (int Flow, y = 0; y < n; y++)
	{
		if (res[x][y] > 0 && (Flow = aug(y, t, min(CurFlow, res[x][y]))))
		{
			res[x][y] -= Flow; res[y][x] += Flow;
			return Flow;
		}
	}
	return 0;
}

//Функция mincut(s, t) находит величину максимального потока между вершинами s и t.
int mincut(int s, int t)
{
	memcpy(res, cap, sizeof cap);
	int x, flow = 0;
	do memset(used, 0, sizeof used);
	while ((x = aug(s, t, 0x7FFFFFFF)) && (flow += x));
	return flow;
}

//Вычисляем максимальный поток от нулевой вершины до s-ой (1 ≤ s ≤ n – 1).
//Среди найденных максимальных потоков ищем минимальный.
int requiredCost()
{
	int best = 0x7FFFFFFF;
	for (int s = 1; s < n; s++)
		best = min(best, mincut(0, s));
	return best;
}

int main() {
	while (scanf("%d\n", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			gets(s);
			for (int j = 0; j < n; j++) cap[i][j] = s[j] - '0';
		}
		printf("%d\n", requiredCost());
	}
	return 0;
}
