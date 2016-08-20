#include <iostream>
#include <algorithm>

using namespace std;

int i, n, m, L, R, mas[50001];

struct Node
{
	int sum, prefix, suffix, max;
} SegTree[120001];

//Функция Merge объединяет соседние отрезки, соответствующие вершинам Left и
//Right. По информации в сыновьях пересчитываются данные в отцовской вершине
//Res, после чего она возвращается в качестве результата функции Merge.
Node Merge(Node Left, Node Right)
{
	Node Res;
	Res.prefix = max(Left.prefix, Left.sum + Right.prefix);
	Res.suffix = max(Right.suffix, Right.sum + Left.suffix);
	Res.sum = Left.sum + Right.sum;
	Res.max = max(max(Left.max, Right.max), Left.suffix + Right.prefix);
	return Res;
}

//На вход процедуре build построения дерева отрезков передается массив a, номер текущей
//вершины дерева v и границы отрезка LeftPos и RightPos, соответствующие вершине v.
void build(int *a, int v, int LeftPos, int RightPos)
{
	if (LeftPos == RightPos)
		SegTree[v].max = SegTree[v].prefix = SegTree[v].suffix =
		SegTree[v].sum = a[LeftPos];
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		build(a, v * 2, LeftPos, Middle);
		build(a, v * 2 + 1, Middle + 1, RightPos);

		//Пересчитываем данные в отцовской вершине через информацию в сыновьях.
		SegTree[v] = Merge(SegTree[v * 2], SegTree[v * 2 + 1]);
	}
}

//Вершине v соответствует отрезок [LeftPos; RightPos]. Функция GetMax вычисляет
//значения четырех параметров (префикс, суффикс, сумма, максимальная сумма) на
//отрезке [Left; Right] и возвращает структуру Node, которая их содержит.
struct Node GetMax(int v, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left == LeftPos && Right == RightPos) return SegTree[v];
	int Middle = (LeftPos + RightPos) / 2;
	if (Right <= Middle) return GetMax(2 * v, LeftPos, Middle, Left, Right);
	if (Left > Middle) return GetMax(2 * v + 1, Middle + 1, RightPos, Left, Right);
	struct Node LeftNode = GetMax(2 * v, LeftPos, Middle, Left, Middle);
	struct Node RightNode = GetMax(2 * v + 1, Middle + 1, RightPos, Middle + 1, Right);
	return Merge(LeftNode, RightNode);
}

int main() {
	//Читаем входные данные. Строим дерево отрезков.
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &mas[i]);
	build(mas, 1, 0, n - 1);

	//Последовательно обрабатываем m запросов.
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &L, &R);
		Node Res = GetMax(1, 0, n - 1, L - 1, R - 1);
		printf("%d\n", Res.max);
	}
	return 0;
}
