#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001
#define NORMAL 0
#define ADD 1
#define SET 2

int i, n, l, q, r, x, cs, type, tests;
long mas[100001];

struct node
{
	long sum, sumSq, type, add;
} SegTree[1 << 18];

//По массиву а строим дерево отрезков, поддерживающее сумму и сумму квадратов на отрезке.
//Тип отложенной операции изначально считается неустановленным (type = NORMAL = 0).
void build(long *a, int Vertex, int Left, int Right)
{
	SegTree[Vertex].type = NORMAL;
	SegTree[Vertex].add = 0;
	if (Left == Right)
	{
		SegTree[Vertex].sum = a[Left];
		SegTree[Vertex].sumSq = 1L * a[Left] * a[Left];
	}
	else
	{
		int Middle = (Left + Right) / 2;
		build(a, 2 * Vertex, Left, Middle);
		build(a, 2 * Vertex + 1, Middle + 1, Right);
		SegTree[Vertex].sum = SegTree[2 * Vertex].sum + SegTree[2 * Vertex + 1].sum;
		SegTree[Vertex].sumSq = SegTree[2 * Vertex].sumSq + SegTree[2 * Vertex + 1].sumSq;
	}
}

void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
	if (SegTree[Vertex].type == SET)
	{
		SegTree[2 * Vertex].type = SegTree[2 * Vertex + 1].type = SegTree[Vertex].type;
		SegTree[2 * Vertex].add = SegTree[2 * Vertex + 1].add = SegTree[Vertex].add;

		SegTree[2 * Vertex].sum = (Middle - LeftPos + 1) * SegTree[Vertex].add;
		SegTree[2 * Vertex].sumSq = (Middle - LeftPos + 1) * SegTree[Vertex].add * SegTree[Vertex].add;

		SegTree[2 * Vertex + 1].sum = (RightPos - Middle) * SegTree[Vertex].add;
		SegTree[2 * Vertex + 1].sumSq = (RightPos - Middle) * SegTree[Vertex].add * SegTree[Vertex].add;

		SegTree[Vertex].add = 0;
		SegTree[Vertex].type = NORMAL;
	}

	if (SegTree[Vertex].type == ADD)
	{
		SegTree[2 * Vertex].add += SegTree[Vertex].add;
		SegTree[2 * Vertex].sumSq += (Middle - LeftPos + 1) *
			SegTree[Vertex].add * SegTree[Vertex].add + 2L * SegTree[Vertex].add * SegTree[2 * Vertex].sum;
		SegTree[2 * Vertex].sum += (Middle - LeftPos + 1) * SegTree[Vertex].add;
		if (SegTree[2 * Vertex].type == NORMAL) SegTree[2 * Vertex].type = ADD;
		if (SegTree[2 * Vertex + 1].type == NORMAL) SegTree[2 * Vertex + 1].type = ADD;

		SegTree[2 * Vertex + 1].add += SegTree[Vertex].add;
		SegTree[2 * Vertex + 1].sumSq += (RightPos - Middle) * SegTree[Vertex].add  *
			SegTree[Vertex].add + 2L * SegTree[Vertex].add * SegTree[2 * Vertex + 1].sum;
		SegTree[2 * Vertex + 1].sum += (RightPos - Middle) * SegTree[Vertex].add;
		SegTree[Vertex].add = 0;
		SegTree[Vertex].type = NORMAL;
	}
}

void SetValue(int Vertex, int LeftPos, int RightPos, int Left, int Right, int Value)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].add = Value;
		SegTree[Vertex].type = SET;
		SegTree[Vertex].sum = (Right - Left + 1L) * Value;
		SegTree[Vertex].sumSq = (Right - Left + 1L) * Value * Value;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);

	SetValue(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right), Value);
	SetValue(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right, Value);

	SegTree[Vertex].sum = SegTree[2 * Vertex].sum + SegTree[2 * Vertex + 1].sum;
	SegTree[Vertex].sumSq = SegTree[2 * Vertex].sumSq + SegTree[2 * Vertex + 1].sumSq;
}

void AddValue(int Vertex, int LeftPos, int RightPos, int Left, int Right, int Value)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].add += Value;
		if (SegTree[Vertex].type == NORMAL) SegTree[Vertex].type = ADD;

		SegTree[Vertex].sumSq += (Right - Left + 1L) * Value * Value + 2L * Value * SegTree[Vertex].sum;
		SegTree[Vertex].sum += (Right - Left + 1L) * Value;
		return;
	}

	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);

	AddValue(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right), Value);
	AddValue(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right, Value);

	SegTree[Vertex].sum = SegTree[2 * Vertex].sum + SegTree[2 * Vertex + 1].sum;
	SegTree[Vertex].sumSq = SegTree[2 * Vertex].sumSq + SegTree[2 * Vertex + 1].sumSq;
}

long SumSq(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;
	if (LeftPos == Left && RightPos == Right) return SegTree[Vertex].sumSq;

	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);

	return SumSq(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right)) +
		SumSq(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main()
{
	scanf("%d", &tests);
	for (cs = 1; cs <= tests; cs++)
	{
		scanf("%d %d", &n, &q);
		for (i = 1; i <= n; i++) scanf("%ld", &mas[i]);
		build(mas, 1, 1, n);
		printf("Case %d:\n", cs);
		while (q--)
		{
			scanf("%d", &type);
			if (type == 0)
			{
				scanf("%d %d %d", &l, &r, &x);
				SetValue(1, 1, n, l, r, x);
			}
			else
				if (type == 1)
				{
					scanf("%d %d %d", &l, &r, &x);
					AddValue(1, 1, n, l, r, x);
				}
				else
				{
					scanf("%d %d", &l, &r);
					printf("%ld\n", SumSq(1, 1, n, l, r));
				}
		}
	}
	return 0;
}
