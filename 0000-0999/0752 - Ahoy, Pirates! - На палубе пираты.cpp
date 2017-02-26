#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX 1024001
#define NORMAL 0
#define SET 1
#define CLEAR 2
#define FLIP 3

using namespace std;

int i, j, k, t, n, m, l, r, tests, cs, q, q1;

struct node
{
	int summa, type;
};

vector<node> SegTree;
char ch, s[100];
int a[MAX];

void build(int *a, int Vertex, int Left, int Right)
{
	SegTree[Vertex].type = NORMAL;
	if (Left == Right) SegTree[Vertex].summa = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		build(a, 2 * Vertex, Left, Middle);
		build(a, 2 * Vertex + 1, Middle + 1, Right);
		SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
	}
}

int ApplyFlip(int type)
{
	if (type == SET) return CLEAR;
	if (type == CLEAR) return SET;
	if (type == FLIP) return NORMAL;
	return FLIP; // type = NORMAL
}

void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
	if (SegTree[Vertex].type == SET)
	{
		SegTree[2 * Vertex].type = SegTree[2 * Vertex + 1].type = SegTree[Vertex].type;
		SegTree[2 * Vertex].summa = Middle - LeftPos + 1;
		SegTree[2 * Vertex + 1].summa = RightPos - Middle;
		SegTree[Vertex].type = NORMAL;
	}
	else
		if (SegTree[Vertex].type == CLEAR)
		{
			SegTree[2 * Vertex].type = SegTree[2 * Vertex + 1].type = SegTree[Vertex].type;
			SegTree[2 * Vertex].summa = SegTree[2 * Vertex + 1].summa = 0;
			SegTree[Vertex].type = NORMAL;
		}
		else
			if (SegTree[Vertex].type == FLIP)
			{
				SegTree[2 * Vertex].type = ApplyFlip(SegTree[2 * Vertex].type);
				SegTree[2 * Vertex + 1].type = ApplyFlip(SegTree[2 * Vertex + 1].type);
				SegTree[2 * Vertex].summa = Middle - LeftPos + 1 - SegTree[2 * Vertex].summa;
				SegTree[2 * Vertex + 1].summa = RightPos - Middle - SegTree[2 * Vertex + 1].summa;
				SegTree[Vertex].type = NORMAL;
			}
}

void Set(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].type = SET;
		SegTree[Vertex].summa = Right - Left + 1;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);
	Set(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right));
	Set(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
	SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
}

void Clear(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].type = CLEAR;
		SegTree[Vertex].summa = 0;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);
	Clear(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right));
	Clear(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
	SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
}

void Flip(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].type = ApplyFlip(SegTree[Vertex].type);
		SegTree[Vertex].summa = Right - Left + 1 - SegTree[Vertex].summa;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);
	Flip(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right));
	Flip(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
	SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
}

int Summa(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;
	if (LeftPos == Left && RightPos == Right) return SegTree[Vertex].summa;
	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);
	return Summa(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right)) +
		Summa(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main()
{
	scanf("%d", &tests);
	for (cs = 1; cs <= tests; cs++)
	{
		scanf("%d", &m); n = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d\n", &t);
			gets(s);
			for (k = 0; k < t; k++)
				for (j = 0; j < strlen(s); j++) a[n++] = s[j] - '0';
		}
		SegTree.resize(4 * n);
		build(a, 1, 0, n - 1);
		printf("Case %d:\n", cs);
		scanf("%d\n", &q); q1 = 1;
		for (j = 0; j < q; j++)
		{
			scanf("%c %d %d\n", &ch, &l, &r);
			if (ch == 'F') Set(1, 0, n - 1, l, r);
			else
				if (ch == 'E') Clear(1, 0, n - 1, l, r);
				else
					if (ch == 'I') Flip(1, 0, n - 1, l, r);
					else printf("Q%d: %d\n", q1++, Summa(1, 0, n - 1, l, r));
		}
	}
	return 0;
}
