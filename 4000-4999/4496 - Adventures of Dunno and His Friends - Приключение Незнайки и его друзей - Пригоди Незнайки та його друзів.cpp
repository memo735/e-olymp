#include <iostream>

using namespace std;

long SegTree[1 << 21];
int i, n, q, x, y, op, Weight, m[1000001];

//По массиву а строим дерево отрезков, поддерживающее сумму.
void BuildTree(int *a, int v, int Left, int Right)
{
	if (Left == Right) SegTree[v] = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, v * 2, Left, Middle);
		BuildTree(a, v * 2 + 1, Middle + 1, Right);
		SegTree[v] = SegTree[v * 2] + SegTree[v * 2 + 1];
	}
}

//Найдем количество последовательных элементов (начиная с первого),
//сумма которых не превышает грузоподъемность воздушного шара Weight.
int Get(int v, int LeftPos, int RightPos, long Weight)
{
	//Если отрезок [LeftPos; RightPos] состоит из одного элемента, то ответ равен 1,
	//если человечка с весом SegTree[v] можно поместить в шар, и 0 иначе.
	if (LeftPos == RightPos) return SegTree[v] <= Weight;
	int Middle = (LeftPos + RightPos) / 2;

	//Если сумма весов SegTree[2 * v] человечков в левом поддереве дерева
	//отрезков больше Weight, то все человечки из левого поддерева не войдут
	//в воздушный шар. Поэтому ответ следует искать только в левом поддереве.
	if (SegTree[2 * v] > Weight) return Get(2 * v, LeftPos, Middle, Weight);

	//Иначе в шар следует посадить всех человечков из левого поддерева (их количество  равно
	//Middle – LeftPos + 1, а их общий вес равен SegTree[2 * v]), а также человечков из правого
	//поддерева начиная с позиции Middle + 1 и далее пока общая сумма весов человечков из правого
	//поддерева не станет больше Weight – SegTree[2 * v].
	return Middle - LeftPos + 1 + Get(2 * v + 1, Middle + 1, RightPos, Weight - SegTree[2 * v]);
}

//Вершине v соответствует отрезок [LeftPos, RightPos]. Изменение единичного
//элемента. В позицию Position записывается элемент NewValue.
void update(int v, int LeftPos, int RightPos, int Position, int NewValue)
{
	if (LeftPos == RightPos) SegTree[v] = NewValue;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) update(v * 2, LeftPos, Middle, Position, NewValue);
		else update(v * 2 + 1, Middle + 1, RightPos, Position, NewValue);
		SegTree[v] = SegTree[v * 2] + SegTree[v * 2 + 1];
	}
}

int main() {
	//Читаем входную последовательность чисел в массив m, начиная с первого индекса.
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &m[i]);

	//Строим дерево отрезков по элементам массива m[1..n].
	BuildTree(m, 1, 1, n);

	//Последовательно обрабатываем запросы.
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &Weight);
			printf("%d\n", Get(1, 1, n, Weight));
		}
		else
		{
			scanf("%d %d", &x, &y);
			update(1, 1, n, x, y);
		}
	}
	return 0;
}
