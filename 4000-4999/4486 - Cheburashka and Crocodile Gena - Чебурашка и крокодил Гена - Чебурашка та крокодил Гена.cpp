#include <iostream>
#include <algorithm>

using namespace std;

int i, n, l, q, r, type, a[1000001];

struct node
{
	long sum;
	int left;
} SegTree[2000001];

//Построение дерева отрезков.
void build(int Vertex, int LeftPos, int RightPos)
{
	if (LeftPos == RightPos) SegTree[Vertex].sum = a[LeftPos];
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		build(2 * Vertex, LeftPos, Middle);
		build(2 * Vertex + 1, Middle + 1, RightPos);
		SegTree[Vertex].sum = SegTree[2 * Vertex].sum + SegTree[2 * Vertex + 1].sum;
	}
}

//Сумма чисел от a до b.
long Sum(int a, int b)
{
	return (a + b) * (b - a + 1L) / 2;
}

//Проталкивание значения из вершины в сыновья.
void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
	if (SegTree[Vertex].left)
	{
		SegTree[2 * Vertex].left = SegTree[Vertex].left;
		SegTree[2 * Vertex].sum = Sum(SegTree[2 * Vertex].left, SegTree[2 * Vertex].left + Middle - LeftPos);
		SegTree[2 * Vertex + 1].left = SegTree[Vertex].left + Middle - LeftPos + 1;
		SegTree[2 * Vertex + 1].sum = Sum(SegTree[2 * Vertex + 1].left, SegTree[2 * Vertex + 1].left + RightPos - Middle - 1);
		SegTree[Vertex].left = 0;
	}
}

//Промежуток[Left; Right] заполняем значениями From, From + 1, From + 2, … .
void Update(int Vertex, int LeftPos, int RightPos, int Left, int Right, int From)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].left = From;
		SegTree[Vertex].sum = Sum(From, From + Right - Left);
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;
	int Mid = Middle - Left + 1;

	//Если отрезок запроса [Left; Right] полностью лежит в правом сыне [Middle + 1; RightPos],
	//то правому сыну передаем значение From без изменений(Mid устанавливаем равным нулю).
	if (Mid < 0) Mid = 0;

	Push(Vertex, LeftPos, Middle, RightPos);
	Update(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right), From);
	Update(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right, From + Mid);
	SegTree[Vertex].sum = SegTree[2 * Vertex].sum + SegTree[2 * Vertex + 1].sum;
}

//Возвращаем сумму чисел на интервале[Left; Right].
long Summa(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;
	if (LeftPos == Left && RightPos == Right) return SegTree[Vertex].sum;
	int Middle = (LeftPos + RightPos) / 2;
	Push(Vertex, LeftPos, Middle, RightPos);
	return Summa(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right)) +
		Summa(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main() {
	//Читаем входной массив чисел. Строим дерево отрезков.
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	build(1, 1, n);

	//Последовательно обрабатываем q запросов.
	scanf("%d", &q);
	for (i = 0; i < q; ++i)
	{
		scanf("%d %d %d", &type, &l, &r);
		if (type == 1) printf("%ld\n", Summa(1, 1, n, l, r));
		else Update(1, 1, n, l, r, 1);
	}
	return 0;
}
