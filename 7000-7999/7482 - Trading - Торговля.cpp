#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long x, SegTree[1200001];

void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
	if (SegTree[Vertex])
	{
		SegTree[2 * Vertex] = max(SegTree[2 * Vertex], SegTree[Vertex]);
		SegTree[2 * Vertex + 1] = max(SegTree[2 * Vertex + 1], SegTree[Vertex] + Middle - LeftPos + 1);
		SegTree[Vertex] = 0;
	}
}

//Продажа шапок на промежутке[Left; Right] начиная с цены x.
void Update(int Vertex, int LeftPos, int RightPos, int Left, int Right, long x)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right) SegTree[Vertex] = max(SegTree[Vertex], x);
	else
	{
		const int Middle = (LeftPos + RightPos) / 2;
		Push(Vertex, LeftPos, Middle, RightPos);
		int len = min(Middle, Right) - Left + 1;
		if (len < 0) len = 0;
		Update(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right), x);
		Update(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right, x + len);
	}
}

//Произведем проталкивание до листов и выведем состояние массива.
void PrintResult(int Vertex, int LeftPos, int RightPos)
{
	if (LeftPos == RightPos) printf("%lld ", SegTree[Vertex]);
	else
	{
		const int Middle = (LeftPos + RightPos) / 2;
		Push(Vertex, LeftPos, Middle, RightPos);
		PrintResult(2 * Vertex, LeftPos, Middle);
		PrintResult(2 * Vertex + 1, Middle + 1, RightPos);
	}
}

int main() {
	int n, m, l, r;
	scanf("%d %d", &n, &m);
	memset(SegTree, 0, sizeof SegTree);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %ld", &l, &r, &x);
		Update(1, 1, n, l, r, x);
	}
	PrintResult(1, 1, n);
	printf("\n");
	return 0;
}
