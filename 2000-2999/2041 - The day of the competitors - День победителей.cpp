#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2000000000

struct Strength
{
	int a, b, c;
} Fight[100001];
int SegmentTree[1 << 18];

//Участников будем упорядочивать по возрастанию первой компоненты.
int cmp(Strength x, Strength y) { return x.a < y.a; }

//Построение дерева отрезков.Во все его вершины заносим значение + ∞.
void BuildTree(int Vertex, int LeftPos, int RightPos)
{
	if (LeftPos == RightPos) SegmentTree[Vertex] = INF;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		BuildTree(2 * Vertex, LeftPos, Middle);
		BuildTree(2 * Vertex + 1, Middle + 1, RightPos);
	}
	SegmentTree[Vertex] = INF;
}

//Вычисление минимума на отрезке.
int GetMin(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return INF;
	if (Left == LeftPos && Right == RightPos) return SegmentTree[Vertex];
	int Middle = (LeftPos + RightPos) / 2;
	return min(GetMin(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)),
		GetMin(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right));
}

//Единичное присваивание : m[Position] = NewValue.
void update(int Vertex, int LeftPos, int RightPos, int Position, int NewValue)
{
	if (LeftPos == RightPos) SegmentTree[Vertex] = NewValue;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) update(2 * Vertex, LeftPos, Middle, Position, NewValue);
		else update(2 * Vertex + 1, Middle + 1, RightPos, Position, NewValue);
		SegmentTree[Vertex] = min(SegmentTree[2 * Vertex], SegmentTree[2 * Vertex + 1]);
	}
}

int main() {
	int i, n, tests, res;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d %d %d", &Fight[i].a, &Fight[i].b, &Fight[i].c);

		//Сортируем участников по первой компоненте.У кого меньшее место – тот и победитель.
		sort(Fight, Fight + n, cmp);

		//Строим дерево отрезков.
		BuildTree(1, 1, n);

		//Последовательно обрабатываем участников.В переменной Result подсчитываем количество наилучших участников.
		for (res = i = 0; i < n; i++)
		{
			int c = GetMin(1, 1, n, 1, Fight[i].b);
			if (c > Fight[i].c)
			{
				res++;
				update(1, 1, n, Fight[i].b, Fight[i].c);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
