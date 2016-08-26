#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2100000000

int i, n, m, q, l, r, mas[1000001];

struct node
{
	int min, max;
} SegTree[1600001] = { 0 };

//По массиву а строим дерево отрезков.
void BuildTree(int *a, int v, int Left, int Right)
{
	if (Left == Right) SegTree[v].min = SegTree[v].max = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, v * 2, Left, Middle);
		BuildTree(a, v * 2 + 1, Middle + 1, Right);
		SegTree[v].min = min(SegTree[v * 2].min, SegTree[v * 2 + 1].min);
		SegTree[v].max = max(SegTree[v * 2].max, SegTree[v * 2 + 1].max);
	}
}

//Функция GetMin возвращает минимум на отрезке[Left, Right].
int GetMin(int v, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return INF;
	if (Left == LeftPos && Right == RightPos) return SegTree[v].min;
	int Middle = (LeftPos + RightPos) / 2;
	return min(GetMin(v * 2, LeftPos, Middle, Left, min(Right, Middle)),
		GetMin(v * 2 + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right));
}

//Функция GetMax возвращает максимум на отрезке[Left, Right].
int GetMax(int v, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return -INF;
	if ((Left == LeftPos) && (Right == RightPos)) return SegTree[v].max;
	int Middle = (LeftPos + RightPos) / 2;
	return max(GetMax(v * 2, LeftPos, Middle, Left, min(Right, Middle)),
		GetMax(v * 2 + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right));
}

//Изменение единичного элемента.В позицию Position записывается элемент NewValue.
void update(int v, int LeftPos, int RightPos, int Position, int NewValue)
{
	if (LeftPos == RightPos) SegTree[v].min = SegTree[v].max = NewValue;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) update(v * 2, LeftPos, Middle, Position, NewValue);
		else update(v * 2 + 1, Middle + 1, RightPos, Position, NewValue);
		SegTree[v].min = min(SegTree[v * 2].min, SegTree[v * 2 + 1].min);
		SegTree[v].max = max(SegTree[v * 2].max, SegTree[v * 2 + 1].max);
	}
}

int main() {
	//Читаем входную последовательность чисел в массив mas, начиная с первого индекса.
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &mas[i]);

	//Строим дерево отрезков по элементам массива mas[1..n].
	BuildTree(mas, 1, 1, n);

	//Последовательно обрабатываем запросы.
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &q, &l, &r);
		//При q = 1 находим минимум и максимум на отрезке [l; r]. Если они равны, то НОД и НОК чисел
		//указанного отрезка одинаковы. Результатом игры является ничья. Иначе Витя выигрывает.
		if (q == 1)
		{
			int min = GetMin(1, 1, n, l, r);
			int max = GetMax(1, 1, n, l, r);
			printf(min == max ? "draw\n" : "wins\n");
		}
		else update(1, 1, n, l, r);
	}
	return 0;
}
