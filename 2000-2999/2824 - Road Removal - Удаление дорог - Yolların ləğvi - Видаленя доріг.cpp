#include <iostream>
#include <vector>

using namespace std;

int a, b, i, n, m, k, cs, res, tests;
vector<int> mas;

struct Edge
{
	int u, v;
	Edge(int a, int b) { u = a; v = b; }
};

vector<Edge> e;

//Функция Repr возвращает представителя множества.
int Repr(int n)
{
	if (n == mas[n]) return n;
	return mas[n] = Repr(mas[n]);
}

//Функция Union объединяет множества, содержащие элементы x и y.
//Возвращает 1, если x и y принадлежат одному множеству.
int Union(int x, int y)
{
	int x1 = Repr(x), y1 = Repr(y);
	mas[x1] = y1;
	return x1 == y1;
}

int main() {
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d %d", &n, &m, &k);
		mas.resize(n, 0); e.clear();

		//Построим систему непересекающихся множеств из вершин графа.
		for (i = 0; i < n; i++) mas[i] = i;

		//Неважные вершины, соединенные ребром, будем объединять в одно
		//множество. В массив e занесем ребра, инцидентные важным городам.
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			if (a >= k && b >= k) Union(a, b);
			else e.push_back(Edge(a, b));
		}
		//В переменной res подсчитаем количество ребер, инцидентных важным вершинам,
		//и которые не попали в остовное дерево. Это значение и будет ответом задачи.
		for (res = i = 0; i < e.size(); i++) res += Union(e[i].u, e[i].v);
		printf("Case #%d: %d\n", ++cs, res);
	}
	return 0;
}
