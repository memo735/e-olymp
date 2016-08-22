#include <iostream>
#include <algorithm>

using namespace std;

int i, k, n, res, tests, a[20001], SegTree[50001];

//Построение дерева отрезков, которое поддерживает битовую операцию AND.
void BuildTree(int *a, int Vertex, int Left, int Right)
{
	if (Left == Right) SegTree[Vertex] = a[Left];
	else
	{
		int Middle = (Left + Right) / 2;
		BuildTree(a, 2 * Vertex, Left, Middle);
		BuildTree(a, 2 * Vertex + 1, Middle + 1, Right);
		SegTree[Vertex] = SegTree[2 * Vertex] & SegTree[2 * Vertex + 1];
	}
}

//Вершине Vertex соответствует отрезок [LeftPos, RightPos].
//Функция Query возвращает значение aLeft & aLeft + 1 & … & aRight.
int Query(int Vertex, int LeftPos, int RightPos, int Left, int Right)
{
	if (Left > Right) return -1;
	if (Left == LeftPos && Right == RightPos) return SegTree[Vertex];
	int Middle = (LeftPos + RightPos) / 2;
	return Query(2 * Vertex, LeftPos, Middle, Left, min(Right, Middle)) &
		Query(2 * Vertex + 1, Middle + 1, RightPos, max(Left, Middle + 1), Right);
}

int main() {
	//Читаем входные данные в массив а.
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		//Если количество раундов k не меньше половины количества элементов
		//массива, то вычисляем AND всех элементов в переменной res.
		if (k >= n / 2)
		{
			for (res = a[0], i = 1; i < n; i++) res &= a[i];
			//Выводим значение res n раз.
			for (i = 0; i < n; i++)
			{
				if (i) printf(" ");
				printf("%d", res);
			}
			printf("\n");
			continue;
		}
		//Для быстрого ответа на каждый тест построим дерево отрезков из элементов массива А.
		BuildTree(a, 1, 0, n - 1);
		//Вычисляем значение Ai после k раундов.Оно равно Ai - k & … & Ai &…& Ai + k. Индексы элементов
		//вычисляются по модулю n. Если(i – k) mod n < (i + k) mod n, то достаточно одного запроса на
		//дереве отрезков. Иначе находим AND элементов от (i – k) mod n до n – 1 и от 0 до(i + k) mod n.
		for (i = 0; i < n; i++)
		{
			int Start = (i - k + n) % n, End = (i + k + n) % n;
			if (Start < End) res = Query(1, 0, n - 1, Start, End);
			else res = Query(1, 0, n - 1, Start, n - 1) & Query(1, 0, n - 1, 0, End);
			if (i) printf(" ");
			printf("%d", res);
		}
		printf("\n");
	}
	return 0;
}
