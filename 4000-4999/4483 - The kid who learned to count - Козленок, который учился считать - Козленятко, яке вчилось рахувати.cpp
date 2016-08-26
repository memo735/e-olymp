#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 1050000000

int i, j, n, k, l, r, q, t, a[1000001], SegTree[1100001];

//Дерево отрезков поддерживает операцию минимума.Но если сумма левого и правого сыновей не больше k, то возвращаем 0.
int f(int a, int b)
{
	if (!a || !b || a + b <= k) return 0;
	return min(a, b);
}

//По массиву а строим дерево отрезков с компаратором f.
void BuildTree(int *a, int Vertex, int Left, int Right)
{
	if (Left == Right) SegTree[Vertex] = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, 2 * Vertex, Left, Middle);
		BuildTree(a, 2 * Vertex + 1, Middle + 1, Right);
		SegTree[Vertex] = f(SegTree[2 * Vertex], SegTree[2 * Vertex + 1]);
	}
}

//Вершине v соответствует отрезок[LeftPos, RightPos].Если на отрезке[Left, Right] существуют два пассажира с суммарной массой не больше k, то функция Query вернет 0. Иначе она вернет наименьший вес пассажира на запрашиваемом отрезке.
int Query(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return MAX_INT;
	if (Left == LeftPos && Right == RightPos) return SegTree[Vertex];
	int Middle = (LeftPos + RightPos) / 2;
	return f(Query(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)),
		Query(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right));
}

//Вершине v соответствует отрезок[LeftPos, RightPos].Изменение единичного элемента.В позицию Position записывается элемент NewValue.
void update(int Vertex, int LeftPos, int RightPos, int Position, int NewValue)
{
	if (LeftPos == RightPos) SegTree[Vertex] = NewValue;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) update(2 * Vertex, LeftPos, Middle, Position, NewValue);
		else update(2 * Vertex + 1, Middle + 1, RightPos, Position, NewValue);
		SegTree[Vertex] = f(SegTree[2 * Vertex], SegTree[2 * Vertex + 1]);
	}
}

int main() {
	//Читаем массы зверей в массив a, начиная с нулевого индекса.
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	//Строим дерево отрезков по элементам массива a[0..n – 1].
	BuildTree(a, 1, 0, n - 1);
	//Последовательно обрабатываем запросы.
	scanf("%d", &q);
	for (j = 0; j < q; j++)
	{
		scanf("%d %d %d", &t, &l, &r);
		if (t == 1)
		{
			int Res = Query(1, 0, n - 1, l - 1, r - 1);
			printf(!Res ? "Yes\n" : "No\n");
		}
		else update(1, 0, n - 1, l - 1, r);
	}
	return 0;
}
