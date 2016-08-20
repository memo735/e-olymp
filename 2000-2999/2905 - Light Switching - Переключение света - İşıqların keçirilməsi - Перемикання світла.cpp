#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int i, n, m, type, Left, Right;

struct node
{
	int summa, add;
};
vector<node> SegTree;

//Если значение add в вершине Vertex не равно нулю, то следует провести
//изменение состояния переключателей во всех элементах левого и правого
//поддерева. После проталкивания add в вершине Vertex ставим равным нулю.
void Push(int Vertex, int LeftPos, int Middle, int RightPos)
{
	if (SegTree[Vertex].add)
	{
		SegTree[2 * Vertex].add ^= SegTree[Vertex].add;
		SegTree[2 * Vertex].summa = Middle - LeftPos + 1 - SegTree[2 * Vertex].summa;
		SegTree[2 * Vertex + 1].add ^= SegTree[Vertex].add;
		SegTree[2 * Vertex + 1].summa = (RightPos - Middle) - SegTree[2 * Vertex + 1].summa;
		SegTree[Vertex].add = 0;
	}
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos]. Функция SwitchValue меняет значения
//всех элементов отрезка[Left; Right] на противоположное(включает или выключает свет).
void SwitchValue(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return;

	//Если [Left; Right] соответствует отрезку, который хранится в вершине дерева [LeftPos; RightPos], то в
	//текущей вершине дерева увеличиваем значение add на единицу по модулю два, а количество включенных
	//лампочек summa на отрезке становится равным числу выключенных до этого на этом же отрезке ламп.
	if (LeftPos == Left && RightPos == Right)
	{
		SegTree[Vertex].add = 1 - SegTree[Vertex].add;
		SegTree[Vertex].summa = (Right - Left + 1) - SegTree[Vertex].summa;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно нулю.
	Push(Vertex, LeftPos, Middle, RightPos);

	//Рекурсивно обрабатываем левого и правого сына текущей вершины дерева отрезков.
	SwitchValue(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right));
	SwitchValue(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);

	//Пересчитываем значение суммы в вершине v через значения сумм ее детей.
	SegTree[Vertex].summa = SegTree[2 * Vertex].summa + SegTree[2 * Vertex + 1].summa;
}

//Вершине Vertex соответствует отрезок [LeftPos; RightPos].
//Функция Summa возвращает значение суммы на отрезке [Left; Right].
int Summa(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;

	//Если [Left; Right] совпадает с отрезком [LeftPos; RightPos], который хранится
	//в вершине Vertex дерева, то возвращаем находящееся в ней значение суммы.
	if (LeftPos == Left && RightPos == Right) return SegTree[Vertex].summa;
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно нулю.
	Push(Vertex, LeftPos, Middle, RightPos);

	//Разбиваем отрезок [Left; Right] на [Left; Middle] и [Middle + 1; Right].
	//Запускаем рекурсивно вычисление сумм на подотрезках.Складываем полученные суммы.
	return Summa(2 * Vertex, LeftPos, Middle, Left, min(Middle, Right)) +
		Summa(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main() {
	//Читаем входные данные. Все элементы дерева отрезков изначально
	//содержат нули. Поэтому строить его нет необходимости.
	scanf("%d %d", &n, &m);
	SegTree.resize(4 * n);

	//Последовательно обрабатываем m запросов.
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &type, &Left, &Right);
		if (type == 1) printf("%d\n", Summa(1, 1, n, Left, Right));
		else SwitchValue(1, 1, n, Left, Right);
	}
	return 0;
}
