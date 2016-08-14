#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, tests, SegTree[2048][2048];

char s[10];
int x, y, xBir, yBir, x2, y2, num, res;

void sety(int xVertex, int xLeftPos, int xRightPos, int yVertex, int yLeftPos, int yRightPos, int yPos, int NewValue)
{
	if (yLeftPos == yRightPos)
	{
		if (xLeftPos == xRightPos) SegTree[xVertex][yVertex] = NewValue;
		else SegTree[xVertex][yVertex] = SegTree[2 * xVertex][yVertex] + SegTree[2 * xVertex + 1][yVertex];
	}
	else
	{
		int Middle = (yLeftPos + yRightPos) / 2;
		if (yPos <= Middle) sety(xVertex, xLeftPos, xRightPos, 2 * yVertex, yLeftPos, Middle, yPos, NewValue);
		else sety(xVertex, xLeftPos, xRightPos, 2 * yVertex + 1, Middle + 1, yRightPos, yPos, NewValue);
		SegTree[xVertex][yVertex] = SegTree[xVertex][2 * yVertex] + SegTree[xVertex][2 * yVertex + 1];
	}
}

void set(int Vertex, int LeftPos, int RightPos, int xPos, int yPos, int NewValue)
{
	if (LeftPos != RightPos)
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (xPos <= Middle) set(2 * Vertex, LeftPos, Middle, xPos, yPos, NewValue);
		else set(2 * Vertex + 1, Middle + 1, RightPos, xPos, yPos, NewValue);
	}
	sety(Vertex, LeftPos, RightPos, 1, 0, n - 1, yPos, NewValue);
}

int gety(int yVertex, int LeftPos, int RightPos, int xVertex, int yLeft, int yRight)
{
	if (yLeft > yRight) return 0;
	if (yLeft == LeftPos && yRight == RightPos) return SegTree[xVertex][yVertex];
	int Middle = (LeftPos + RightPos) / 2;
	return gety(2 * yVertex, LeftPos, Middle, xVertex, yLeft, min(yRight, Middle)) +
		gety(2 * yVertex + 1, Middle + 1, RightPos, xVertex, max(yLeft, Middle + 1), yRight);

}

int get(int Vertex, int LeftPos, int RightPos, int xLeft, int yLeft, int xRight, int yRight)
{
	if (xLeft > xRight) return 0;
	if (xLeft == LeftPos && xRight == RightPos) return gety(1, 0, n - 1, Vertex, yLeft, yRight);
	int Middle = (LeftPos + RightPos) / 2;
	return get(2 * Vertex, LeftPos, Middle, xLeft, yLeft, min(xRight, Middle), yRight) +
		get(2 * Vertex + 1, Middle + 1, RightPos, max(xLeft, Middle + 1), yLeft, xRight, yRight);
}

int main()
{
	scanf("%d", &tests);
	while (tests--)
	{
		memset(SegTree, 0, sizeof SegTree);
		scanf("%d", &n);
		while (scanf("%s ", s), strcmp(s, "END"))
		{
			if (!strcmp(s, "SET")) // set
			{
				scanf("%d %d %d", &x, &y, &num);
				set(1, 0, n - 1, x, y, num);
			}
			else // sum
			{
				scanf("%d %d %d %d", &xBir, &yBir, &x2, &y2);
				res = get(1, 0, n - 1, xBir, yBir, x2, y2);
				printf("%d\n", res);
			}
		}
		printf("\n");
	}
	return 0;
}
