#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 850001
int mas[MAX];

struct Edge
{
	int x, y, danger;
} e[MAX];

//Функция Repr находит представителя множества, в котором находится n.
//При этом для избежания вердикта Time Limit используется эвристика :
//если представителем вершины x является n, то следует положить mas[x] = n.
int Repr(int n)
{
	if (n == mas[n]) return n;
	return mas[n] = Repr(mas[n]);
}

//Объединение множеств, содержащих элементы x и y.
int Union(int x, int y)
{
	int x1 = Repr(x), y1 = Repr(y);
	mas[x1] = y1;
	return x1 != y1;
}

//Функция сравнения ребер. Дороги сортируются по возрастанию их опасности.
int lt(Edge a, Edge b)
{
	return a.danger < b.danger;
}

int main() {
	//Читаем ребра графа в массив ребер e.
	int i, n, m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) mas[i] = i;
	for (i = 0; i < m; i++) scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].danger);

	//Сортируем ребра по величине опасности.
	sort(e, e + m, lt);

	//Перебираем ребра, начиная с наименее опасного. Объединяем множества,
	//содержащие их вершины. Как только вершины 1 и n попадут в одно множество 
	//(Repr(1) станет равным Repr(n)), самый безопасный путь будет найден.
	//Его опасность будет равна опасности последнего обрабатываемого ребра, то есть e[i].danger.
	for (i = 0; i < m; i++)
	{
		Union(e[i].x, e[i].y);
		if (Repr(1) == Repr(n)) break;
	}
	printf("%d\n", e[i].danger);
	return 0;
}
