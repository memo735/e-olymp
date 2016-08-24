#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int i, n, m, l, q, r, mas[MAX], SegTree[170001];

int gcd(int a, int b)
{
	return b > 0 ? gcd(b, a%b) : a;
}

//По массиву а строим дерево отрезков.
void BuildTree(int *a, int v, int Left, int Right)
{
	if (Left == Right) SegTree[v] = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, v * 2, Left, Middle);
		BuildTree(a, v * 2 + 1, Middle + 1, Right);
		SegTree[v] = gcd(SegTree[v * 2], SegTree[v * 2 + 1]);
	}
}

//Вершине v соответствует отрезок [LeftPos, RightPos].
//Функция возвращает НОД на отрезке [Left, Right].
int GetGCD(int v, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;
	if (Left == LeftPos && Right == RightPos) return SegTree[v];
	int Middle = (LeftPos + RightPos) / 2;
	return gcd(GetGCD(v * 2, LeftPos, Middle, Left, min(Right, Middle)),
		GetGCD(v * 2 + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right));
}

//Вершине v соответствует отрезок[LeftPos, RightPos]. Изменение
//единичного элемента. В позицию Position записывается элемент NewValue.
void update(int v, int LeftPos, int RightPos, int Position, int NewValue)
{
	if (LeftPos == RightPos) SegTree[v] = NewValue;
	else
	{
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) update(v * 2, LeftPos, Middle, Position, NewValue);
		else update(v * 2 + 1, Middle + 1, RightPos, Position, NewValue);
		SegTree[v] = gcd(SegTree[v * 2], SegTree[v * 2 + 1]);
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
		if (q == 1) printf("%d\n", GetGCD(1, 1, n, l, r));
		else update(1, 1, n, l, r);
	}
	return 0;
}
