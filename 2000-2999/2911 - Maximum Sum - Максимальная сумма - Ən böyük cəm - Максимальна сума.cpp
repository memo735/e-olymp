#include <iostream>
#include <algorithm>

using namespace std;

int i, j, n, q, x, y, a[100001];
char ch;

struct node
{
	int max1, max2;
} SegTree[201501];

//Строим дерево отрезков из элементов массива а, поддерживающее первый и второй максимум.
void BuildTree(int *a, int Vertex, int Left, int Right)
{
	//Для вершины Vertex, соответствующей отрезку из одного элемента (когда Left = Right)
	//первым максимумом считаем значение a[Left], а второй положим равным нулю.
	if (Left == Right)
	{
		SegTree[Vertex].max1 = a[Left];
		SegTree[Vertex].max2 = 0;
	}
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, 2 * Vertex, Left, Middle);
		BuildTree(a, 2 * Vertex + 1, Middle + 1, Right);

		//Сортируем первый и второй максимумы левого и правого сына. Наибольшее значение temp[3] заносим
		//в первый максимум вершины Vertex.Второе наибольшее значение temp[2] заносим  во второй максимум.
		int temp[] = { SegTree[2 * Vertex].max1, SegTree[2 * Vertex].max2, SegTree[2 * Vertex + 1].max1, SegTree[2 * Vertex + 1].max2 };
		sort(temp, temp + 4);
		SegTree[Vertex].max1 = temp[3];
		SegTree[Vertex].max2 = temp[2];
	}
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos]. Функция Query возвращает
//структуру node, содержащую первый и второй максимум на отрезке[Left; Right].
node Query(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right)
	{
		node n; n.max1 = n.max2 = 0;
		return n;
	}
	if (Left == LeftPos && Right == RightPos) return SegTree[Vertex];
	int Middle = (LeftPos + RightPos) / 2;
	node L = Query(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle));
	node R = Query(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
	node Result;
	int temp[] = { L.max1, L.max2, R.max1, R.max2 };
	sort(temp, temp + 4);
	Result.max1 = temp[3]; Result.max2 = temp[2];
	return Result;
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos]. Функция
//Update присваивает элементу с индексом Position значение NewValue.
void update(int Vertex, int LeftPos, int RightPos, int Position, int NewValue)
{
	if (LeftPos == RightPos)
	{
		SegTree[Vertex].max1 = NewValue;
		SegTree[Vertex].max2 = 0;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;
	if (Position <= Middle) update(2 * Vertex, LeftPos, Middle, Position, NewValue);
	else update(2 * Vertex + 1, Middle + 1, RightPos, Position, NewValue);
	int temp[] = { SegTree[2 * Vertex].max1, SegTree[2 * Vertex].max2, SegTree[2 * Vertex + 1].max1, SegTree[2 * Vertex + 1].max2 };
	sort(temp, temp + 4);
	SegTree[Vertex].max1 = temp[3];
	SegTree[Vertex].max2 = temp[2];
}

int main() {
	//Читаем входную последовательность аi в массив а.
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	//Строим дерево отрезков, поддерживающее первый и второй максимумы.
	BuildTree(a, 1, 0, n - 1);

	//Читаем последовательно q запросов и обрабатываем их.
	scanf("%d", &q);
	for (j = 0; j < q; j++)
	{
		scanf("\n%c ", &ch);
		if (ch == 'Q')
		{
			scanf("%d %d", &x, &y);
			node Res = Query(1, 0, n - 1, x - 1, y - 1);
			printf("%d\n", Res.max1 + Res.max2);
		}
		else
		{
			scanf("%d %d", &i, &x);
			update(1, 0, n - 1, i - 1, x);
		}
	}
	return 0;
}
