#include <iostream>
#include <algorithm>

using namespace std;

int k, n, l, r, x;
char c;

struct node
{
	long summa, add;
} SegTree[1 << 18];

//Строим дерево отрезков. Значение add в каждой вершине инициализируем - 1
//(значением, которое не может присваиваться элементам отрезка).
void build(int Vertex, int Left, int Right)
{
	if (Left == Right)
	{
		SegTree[Vertex].summa = 0;
		SegTree[Vertex].add = -1;
	}
	else
	{
		int Middle = (Left + Right) / 2;
		build(2 * Vertex, Left, Middle);
		build(2 * Vertex + 1, Middle + 1, Right);
		SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
		SegTree[Vertex].add = -1;
	}
}

//Если значение add в вершине Vertex отлично от - 1, то следует его протолкнуть
//на один уровень вниз.После проталкивания add в вершине Vertex ставим равным - 1.
void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
	if (SegTree[Vertex].add != -1)
	{
		SegTree[2 * Vertex].add = SegTree[Vertex].add;
		SegTree[2 * Vertex].summa = (Middle - LeftPos + 1) * SegTree[Vertex].add;
		SegTree[2 * Vertex + 1].add = SegTree[Vertex].add;
		SegTree[2 * Vertex + 1].summa = (RightPos - Middle) * SegTree[Vertex].add;
		SegTree[Vertex].add = -1;
	}
}

//Вершине v соответствует отрезок [LeftPos; RightPos]. Функция SetValue
//устанавливает все элементы отрезка[Left; Right] равными Value.
void SetValue(int Vertex, int LeftPos, int RightPos, int Left, int Right, int Value)
{
	if (Left > Right) return;

	//Если [Left; Right] соответствует отрезку, который хранится в вершине дерева [LeftPos; RightPos],
	//то присваиваем в текущей вершине дерева переменным add и summa соответствующие значения.
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].add = Value;
		SegTree[Vertex].summa = (Right - Left + 1L) * Value;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно - 1.
	Push(Vertex, LeftPos, Middle, RightPos);

	//Рекурсивно обрабатываем левого и правого сына текущей вершины дерева отрезков.
	SetValue(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right), Value);
	SetValue(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right, Value);

	//Пересчитываем значение суммы в вершине v через значения сумм ее детей.
	SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos].
//Функция Summa возвращает значение суммы на отрезке[Left; Right].
long Summa(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;

	//Если [Left; Right] совпадает с отрезком [LeftPos; RightPos], который хранится
	//в вершине Vertex дерева, то возвращаем находящееся в ней значение суммы.
	if (LeftPos == Left && RightPos == Right) return SegTree[Vertex].summa;
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно - 1.
	Push(Vertex, LeftPos, Middle, RightPos);

	//Разбиваем отрезок[Left; Right] на [Left; Middle] и[Middle + 1; Right].Запускаем рекурсивно вычисление сумм на подотрезках.Складываем полученные суммы.
	return Summa(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right)) +
		Summa(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main() {
	//При помощи функции build строим дерево отрезков. В зависимости от входного
	//запроса совершаем либо групповое присваивание, либо вычисление суммы на отрезке.
	scanf("%d %d\n", &n, &k);
	build(1, 0, n);
	while (k--)
	{
		scanf("%c ", &c);
		if (c == 'A')
		{
			scanf("%d %d %d\n", &l, &r, &x);
			SetValue(1, 0, n, l, r, x);
		}
		else
		{
			scanf("%d %d\n", &l, &r);
			printf("%ld\n", Summa(1, 0, n, l, r));
		}
	}
	return 0;
}
