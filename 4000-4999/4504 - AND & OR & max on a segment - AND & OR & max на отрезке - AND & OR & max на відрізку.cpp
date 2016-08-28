#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2000000000

struct node
{
	int max, orOp;
} SegTree[1 << 18];

int i, L, R, n, m, res, mas[100001];
char s[3];

void build(int *a, int Vertex, int LeftPos, int RightPos)
{
	if (LeftPos == RightPos) SegTree[Vertex].orOp = SegTree[Vertex].max = a[LeftPos];
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		build(a, 2 * Vertex, LeftPos, Middle);
		build(a, 2 * Vertex + 1, Middle + 1, RightPos);

		SegTree[Vertex].orOp = SegTree[2 * Vertex].orOp | SegTree[2 * Vertex + 1].orOp;
		SegTree[Vertex].max = max(SegTree[2 * Vertex].max, SegTree[2 * Vertex + 1].max);
	}
}

int GetOr(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;
	if (Left == LeftPos && Right == RightPos) return SegTree[Vertex].orOp;

	int Middle = (LeftPos + RightPos) / 2;
	return GetOr(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)) |
		GetOr(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int GetMax(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return -INF;
	if (Left == LeftPos && Right == RightPos) return SegTree[Vertex].max;

	int Middle = (LeftPos + RightPos) / 2;
	return max(GetMax(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)),
		GetMax(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right));
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &mas[i]);
	build(mas, 1, 1, n);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s %d %d", s, &L, &R);
		if (s[0] == 'A') res = GetMax(1, 1, n, L, R);
		else res = GetOr(1, 1, n, L, R);
		printf("%d\n", res);
	}
	return 0;
}
