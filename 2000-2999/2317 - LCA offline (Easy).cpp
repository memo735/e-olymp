#include <iostream>
#include <vector>

using namespace std;

#define MAX 1010
#define LOGMAX 10

int a, b, k, i, j, mas[2 * MAX][LOGMAX + 1];
char op[3];

//Дерево храним как граф в списке смежности g. Массивы Order, Height и First используются
//для сведения задачи LCA к RMQ.Все поступающие запросы поместим в массив пар Query.
vector<vector<int> > g;
vector<int> Order, used, Height, First;
vector<pair<int, int> > Query;
int *hRMQ;

//По массиву a размера size строим массив mas, для которого
//mas[i][j] = arg min(a[i], a[i + 1], …, a[i + 2 ^ j - 1])
void BuildRMQ(int *a, int size)
{
	for (i = 0; i <= size; i++) mas[i][0] = i;
	for (j = 1; 1 << j <= size; j++)
		for (i = 1; i + (1 << j) - 1 <= size; i++)
			if (a[mas[i][j - 1]] < a[mas[i + (1 << (j - 1))][j - 1]]) mas[i][j] = mas[i][j - 1];
			else mas[i][j] = mas[i + (1 << (j - 1))][j - 1];
}

//Функция RMQ возвращает минимум на отрезке (a[i], a[i + 1], …, a[j]) за O(1).
int RMQ(int i, int j)
{
	if (i > j) swap(i, j);
	int k = 0;
	while (1 << (k + 1) <= j - i + 1) k++;
	int res = mas[i][k];
	if (hRMQ[mas[j - (1 << k) + 1][k]] < hRMQ[res]) res = mas[j - (1 << k) + 1][k];
	return res;
}

//Обход дерева в глубину. Порядок обхода вершин дерева (с фиксированием времени захода
//в вершину и возвращения в нее) сохраняем в массиве Order, их высоты – в массиве Height.
//Вызов dfs(v, h) означает, что стартует поиск в глубину из вершины v, имеющей высоту h.
void dfs(int v, int h = 0)
{
	used[v] = 1;
	Order.push_back(v);
	Height[v] = h;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
		{
			dfs(to, h + 1);
			Order.push_back(v);
		}
	}
}

//Препроцессинг LCA. Запускаем обход дерева в глубину. Построение вспомогательных массивов.
//Выполняем препроцессинг RMQ по массиву hRMQ, который содержит высоты последовательности вершин.
void Init_LCA()
{
	Order.push_back(0);
	used.assign(MAX, 0); Height.assign(MAX, 0); First.assign(MAX, 0);
	dfs(1);

	//First[i] содержит момент времени, в который обход в глубину впервые заходит в вершину i.
	for (int i = 1; i < Order.size(); i++) if (!First[Order[i]]) First[Order[i]] = i;
	hRMQ = new int[Order.size()];
	hRMQ[0] = 0;
	for (int i = 1; i < Order.size(); i++) hRMQ[i] = Height[Order[i]];
	BuildRMQ(hRMQ, Order.size());
}

//Функция LCA возвращает вершину дерева, являющуюся LCA(i, j).
int LCA(int i, int j)
{
	int index = RMQ(First[i], First[j]);
	return Order[index];
}

int main() {
	//Читаем входное дерево, заполняем структуру g.Запросы собираем в массив пар Query.
	scanf("%d\n", &k);
	g.assign(MAX, vector<int>());
	for (i = 0; i < k; i++)
	{
		scanf("%s %d %d\n", op, &a, &b);
		if (op[0] == 'A')
		{
			g[a].push_back(b);
			g[b].push_back(a);
		}
		else Query.push_back(make_pair(a, b));
	}
	//Сводим задачу LCA к RMQ.
	Init_LCA();
	//Последовательно обрабатываем запросы.Выводим ответ на каждый из них за O(1).
	for (i = 0; i < Query.size(); i++) printf("%d\n", LCA(Query[i].first, Query[i].second));
	return 0;
}
