#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, SegTree(1 << 20, 0);
int d, f, i, j, n, q, t;
char c;

//На вход процедуре build построения дерева отрезков передается
//массив a, номер текущей вершины дерева Vertex и границы отрезка
//LeftPos и RightPos, соответствующие вершине Vertex.
void BuildTree(vector<int>&a, int Vertex, int Left, int Right)
{
	if (Left == Right) SegTree[Vertex] = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, 2 * Vertex, Left, Middle);
		BuildTree(a, 2 * Vertex + 1, Middle + 1, Right);
		SegTree[Vertex] = SegTree[2 * Vertex] + SegTree[2 * Vertex + 1];
	}
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos]. Функция
//Update присваивает элементу с индексом Position значение NewValue.
void Update(int Vertex, int LeftPos, int RightPos, int Position, int NewValue)
{
	//Если вершине Vertex соответствует отрезок, состоящий из одного элемента (LeftPos равно
	//RightPos), то мы дошли до листа дерева отрезков.Присваиваем ему значение NewValue.
	if (LeftPos == RightPos) SegTree[Vertex] = NewValue;
	else
	{
		//Иначе вычисляем, в каком – левом или правом сыне вершины Vertex лежит
		//элемент с индексом Position. Запускаем рекурсивно его модификацию.
		int Middle = (LeftPos + RightPos) / 2;
		if (Position <= Middle) Update(2 * Vertex, LeftPos, Middle, Position, NewValue);
		else Update(2 * Vertex + 1, Middle + 1, RightPos, Position, NewValue);

		//Пересчитываем значение суммы в текущей вершине дерева отрезков.
		SegTree[Vertex] = SegTree[2 * Vertex] + SegTree[2 * Vertex + 1];
	}
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos].
//Функция Summa возвращает значение суммы на отрезке [Left; Right].
int Summa(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;

	//Если [Left; Right] совпадает с отрезком [LeftPos; RightPos], который хранится
	//в вершине Vertex дерева, то возвращаем находящееся в ней значение суммы.
	if (Left == LeftPos && Right == RightPos) return SegTree[Vertex];
	int Middle = (LeftPos + RightPos) / 2;

	//Разбиваем отрезок[Left; Right] на[Left; Middle] и[Middle + 1; Right].Запускаем рекурсивно вычисление сумм на подотрезках.Складываем полученные суммы.
	return Summa(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)) +
		Summa(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main() {
	//Читаем входные данные. По данным в массиве v строим дерево отрезков.
	scanf("%d %d\n", &n, &q);
	v.resize(n + 1);
	for (i = 1; i <= n; i++) scanf("%d", &v[i]); scanf("\n");
	BuildTree(v, 1, 0, n);

	//Последовательно обрабатываем q запросов. В зависимости от типа запроса
	//производим либо модификацию элемента либо вычисление суммы на отрезке.
	for (j = 0; j < q; j++)
	{
		scanf("%c ", &c);
		if (c == '=')
		{
			scanf("%d %d\n", &i, &d);
			Update(1, 0, n, i, d);
		}
		else
		{
			scanf("%d %d\n", &f, &t);
			printf("%d\n", Summa(1, 0, n, f, t));
		}
	}
	return 0;
}
