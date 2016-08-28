#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 50016

vector<vector<int>> g;
int i, j, k, n, res, MaskLen, bits[1 << 16], used[MAX], mask[MAX][MAX / 32];

//Поиск в глубину из вершины v.
void dfs(int v)
{
	int i, j, to;
	used[v] = 1;
	for (i = 0; i < g[v].size(); i++)
	{
		to = g[v][i];
		if (!used[to]) dfs(to);

		//Для каждого сына to вершины v совершаем операцию mask[v] = mask[v] OR mask[to].
		for (j = 0; j < MaskLen; j++) mask[v][j] |= mask[to][j];

		//Добавим в маску вершины v вершину to.
		mask[v][to >> 5] |= 1 << (to & 31);
	}
}

//Препроцессинг массива bits. Ячейка bits[i] содержит количество единиц в бинарном представлении числа i.
int gen(int mask)
{
	if (!mask) return 0;
	if (bits[mask]) return bits[mask];
	for (int i = 0; i < 32; i++)
		if (mask & 1 << i) bits[mask] = gen(mask ^ 1 << i) + 1;
	return bits[mask];
}

int main() {
	memset(bits, 0, sizeof bits);
	gen((1 << 16) - 1);
	scanf("%d %d", &n, &k);
	g.resize(n);
	while (k--)
	{
		scanf("%d %d", &i, &j);
		g[i - 1].push_back(j - 1);
	}
	//В ячейке типа int содержится 32 бита, граф содержит n вершин. Для хранения маски
	//длины n бит достаточно использовать целочисленный массив длины MaskLen = [n/32].
	MaskLen = (n + 31) / 32;

	//Запускаем поиск в глубину, в котором строятся маски достижимости для каждой вершины.
	for (i = 0; i < n; i++) if (!used[i]) dfs(i);

	//Остается подсчитать количество единиц во всех масках mask[i](0 ≤ i ≤ n – 1).
	for (res = 0, i = 0; i < n; i++)
		for (j = 0; j < MaskLen; j++) res += bits[mask[i][j] & 65535] + bits[mask[i][j] >> 16 & 65535];

	//Выводим количество ребер в транзитивном замыкании графа.
	printf("%d\n", res);
	return 0;
}
