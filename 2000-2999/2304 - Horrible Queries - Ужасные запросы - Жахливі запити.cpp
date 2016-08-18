#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int c, i, n, p, q, v, tests, command;

struct node
{
	long summa, add;
} t[1 << 18];

//Если значение add в вершине v отлично от нуля, то следует его протолкнуть
//на один уровень вниз. После проталкивания add в вершине v ставим равным нулю.
void Push(int v, int LeftPos, int Middle, int RightPos)
{
	if (t[v].add)
	{
		t[2 * v].add += t[v].add;
		t[2 * v].summa += (Middle - LeftPos + 1) * t[v].add;
		t[2 * v + 1].add += t[v].add;
		t[2 * v + 1].summa += (RightPos - Middle) * t[v].add;
		t[v].add = 0;
	}
}

//Вершине v соответствует отрезок [LeftPos; RightPos]. Функция
//AddValue прибавляет ко всем элементам отрезка[L; R] значение Value.
void AddValue(int v, int LeftPos, int RightPos, int L, int R, int Value)
{
	if (L > R) return;

	//Если [L; R] соответствует отрезку, который хранится в вершине дерева [LeftPos; RightPos],
	//то прибавляем в текущей вершине дерева переменным add и summa соответствующие значения.
	if (LeftPos == L && RightPos == R)
	{
		t[v].add += Value;
		t[v].summa += 1LL * (R - L + 1) * Value;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно нулю.
	Push(v, LeftPos, Middle, RightPos);

	//Рекурсивно обрабатываем левого и правого сына текущей вершины дерева отрезков.
	AddValue(2 * v, LeftPos, Middle, L, min(Middle, R), Value);
	AddValue(2 * v + 1, Middle + 1, RightPos, max(L, Middle + 1), R, Value);

	//Пересчитываем значение суммы в вершине v через значения сумм ее детей.
	t[v].summa = t[2 * v].summa + t[2 * v + 1].summa;
}

//Вершине v соответствует отрезок [LeftPos; RightPos].
//Функция Summa возвращает значение суммы на отрезке[L; R].
long Summa(int v, int LeftPos, int RightPos, int L, int R)
{
	if (L > R) return 0;

	//Если [L; R] совпадает с отрезком [LeftPos; RightPos], который хранится
	//в вершине v дерева, то возвращаем находящееся в ней значение суммы.
	if (LeftPos == L && RightPos == R) return t[v].summa;
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно нулю.
	Push(v, LeftPos, Middle, RightPos);

	//Разбиваем отрезок [L; R] на [L; Middle] и [Middle + 1; R]. Запускаем
	//рекурсивно вычисление сумм на подотрезках. Складываем полученные суммы.
	return Summa(2 * v, LeftPos, Middle, L, min(Middle, R)) +
		Summa(2 * v + 1, Middle + 1, RightPos, max(L, Middle + 1), R);
}

int main() {
	scanf("%d", &tests);
	while (tests--)
	{
		//Для каждого теста читаем входные данные и строим дерево отрезков.
		//Поскольку изначально все элементы дерева отрезков равны нулю (значение
		//add каждой вершины можно проинициализировать нулем, так как по условию
		//задачи в командах прибавляемое значение всегда натурально и не может
		//равняться нулю), то в качестве инициализации достаточно просто заполнить
		//нулями массив t. Функцию построения дерева отрезков можно не использовать.

		scanf("%d %d", &n, &c);
		memset(t, 0, sizeof t);
		//Последовательно обрабатываем c команд.
		for (i = 0; i < c; i++)
		{
			scanf("%d %d %d", &command, &p, &q);
			if (command == 0)
			{
				scanf("%d", &v);
				AddValue(1, 0, n - 1, p - 1, q - 1, v);
			}
			else printf("%ld\n", Summa(1, 0, n - 1, p - 1, q - 1));
		}
	}
	return 0;
}
