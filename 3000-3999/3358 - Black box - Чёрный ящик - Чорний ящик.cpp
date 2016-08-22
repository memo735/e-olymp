#include <iostream>

using namespace std;

#define MAX 1000001

int n, x;
char c;

struct node
{
	int x, frequency;
} SegmentTree[2100001];

//Сравнение элементов.
struct node max(node a, node b)
{
	if (a.frequency > b.frequency) return a;
	if (a.frequency == b.frequency && a.x < b.x) return a;
	return b;
}

//Построение дерева отрезков.
void BuildTree(int Vertex, int Left, int Right)
{
	if (Left == Right)
	{
		SegmentTree[Vertex].x = Left;
		SegmentTree[Vertex].frequency = 0;
	}
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(2 * Vertex, Left, Middle);
		BuildTree(2 * Vertex + 1, Middle + 1, Right);
		SegmentTree[Vertex] = max(SegmentTree[2 * Vertex], SegmentTree[2 * Vertex + 1]);
	}
}

//Прибавление a[Position] += Value.
void Add(int Vertex, int LeftPos, int RightPos, int Position, int Value)
{
	if (LeftPos == RightPos) SegmentTree[Vertex].frequency += Value;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) Add(2 * Vertex, LeftPos, Middle, Position, Value);
		else Add(2 * Vertex + 1, Middle + 1, RightPos, Position, Value);
		SegmentTree[Vertex] = max(SegmentTree[2 * Vertex], SegmentTree[2 * Vertex + 1]);
	}
}

int main() {
	//Строим дерево отрезков.
	scanf("%d\n", &n);
	BuildTree(1, 0, MAX - 1);

	//Последовательно обрабатываем запросы.
	while (n--)
	{
		scanf("%c %d\n", &c, &x);
		if (c == '+') Add(1, 0, MAX - 1, x, 1);
		else Add(1, 0, MAX - 1, x, -1);
		printf("%d\n", SegmentTree[1].x);
	}
	return 0;
}
