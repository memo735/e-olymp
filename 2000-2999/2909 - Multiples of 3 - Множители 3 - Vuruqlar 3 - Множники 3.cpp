#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int i, n, m, L, R, type;

struct node
{
	int ones, twos, add;
} st[1 << 18];

//В вершину VSun сверху производится проталкивание значения add (0 ≤ add ≤ 2). Вершина VSun
//является левым сыном, если SunType = 'L' и правым если SunType = 'R'. Отцу вершины VSun
//соответствует отрезок [LeftPos, RightPos], Middle = (LeftPos + RightPos) / 2. Будем add
//раз производить в вершине VSun циклический сдвиг количества нулей, единиц и двоек. Каждый
//циклический сдвиг соответствует проталкиванию единицы из отца в VSun.
void MakeShift(int VSun, int add, char SunType, int LeftPos, int Middle, int RightPos)
{
	st[VSun].add = (st[VSun].add + add) % 3;
	while (add--)
	{
		//Количество двоек становится равным числу единиц. Количество единиц становится равным числу нулей.
		int _Ones = st[VSun].ones;

		//Количество единиц становится равным числу нулей. Проталкивание происходит в левом сыне, если
		//SunType = 'L'. Если VSun является левым сыном, то длина соответствующего ему отрезка равна
		//Middle – LeftPos + 1. Если правым сыном, то RightPos – Middle.
		if (SunType == 'L') st[VSun].ones = Middle - LeftPos + 1 - st[VSun].ones - st[VSun].twos;
		else st[VSun].ones = RightPos - Middle - st[VSun].ones - st[VSun].twos;

		//Количество двоек становится равным числу единиц.
		st[VSun].twos = _Ones;
	}
}

//Если значение add в вершине v отлично от нуля, то следует его протолкнуть на один уровень
//вниз. После проталкивания add в вершине v ставим равным нулю. Значение add в сыновьях v
//увеличиваем на протолкнутое значение. Пересчитываем значения ones и twos в сыновьях.
void Push(int v, int LeftPos, int Middle, int RightPos)
{
	MakeShift(2 * v, st[v].add, 'L', LeftPos, Middle, RightPos);
	MakeShift(2 * v + 1, st[v].add, 'R', LeftPos, Middle, RightPos);
	st[v].add = 0;
}

//Вершине v соответствует отрезок [LeftPos; RightPos ]. Функция IncValue
//прибавляет ко всем элементам отрезка[Left; Right] значение 1.
void IncValue(int v, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return;
	if (LeftPos == Left && RightPos == Right)
	{
		st[v].add = (st[v].add + 1) % 3;
		int _Ones = st[v].ones;
		st[v].ones = Right - Left + 1 - st[v].ones - st[v].twos;
		st[v].twos = _Ones;
		return;
	}
	int Middle = (LeftPos + RightPos) / 2;

	//Проведем проталкивание, если add не равно нулю.
	Push(v, LeftPos, Middle, RightPos);

	//Рекурсивно обрабатываем левого и правого сына текущей вершины дерева отрезков.
	IncValue(2 * v, LeftPos, Middle, Left, min(Middle, Right));
	IncValue(2 * v + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);

	//Пересчитываем количество единиц и двоек на отрезке, соответствующему вершине v, через соответствующие значения детей.
	st[v].ones = st[2 * v].ones + st[2 * v + 1].ones;
	st[v].twos = st[2 * v].twos + st[2 * v + 1].twos;
}

//Вершине v соответствует отрезок [LeftPos; RightPos]. Функция Query возвращает количество нулей на отрезке [Left; Right].
int Query(int v, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return 0;

	//Количество нулей на отрезке равно длине отрезка минус количество единиц и двоек на нем.
	if (LeftPos == Left && RightPos == Right) return (RightPos - LeftPos + 1) - st[v].ones - st[v].twos;
	int Middle = (LeftPos + RightPos) / 2;
	Push(v, LeftPos, Middle, RightPos);
	return Query(2 * v, LeftPos, Middle, Left, min(Middle, Right)) +
		Query(2 * v + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main() {
	//Последовательно обрабатываем m команд.
	memset(st, 0, sizeof st);
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &type, &L, &R);
		if (type) printf("%d\n", Query(1, 0, n - 1, L, R));
		else IncValue(1, 0, n - 1, L, R);
	}
	return 0;
}
