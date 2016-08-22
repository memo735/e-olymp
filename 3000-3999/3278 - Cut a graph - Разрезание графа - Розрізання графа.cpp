#include <iostream>

using namespace std;

#define MAX 150001
char op[20];
int i, n, m, k, u, v, mas[3][MAX], dsu[MAX], res[MAX];

//Функция Repr возвращает представителя множества, которому принадлежит вершина n.
int Repr(int n)
{
	if (n == dsu[n]) return n;
	return dsu[n] = Repr(dsu[n]);
}

//Объединение множеств, которым принадлежат вершины x и y.
int Union(int x, int y)
{
	int x1 = Repr(x), y1 = Repr(y);
	dsu[x1] = y1;
	return x1 == y1;
}

int main() {
	//Читаем значения n, m, k. Начальное состояние графа можно пропустить.
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < m; i++) scanf("%d %d", &u, &v);
	scanf("\n");

	//Входные запросы сохраняем в массиве mas.
	for (i = 0; i < k; i++)
	{
		scanf("%s %d %d\n", op, &mas[1][i], &mas[2][i]);
		if (op[0] == 'a') mas[0][i] = 1;
		else mas[0][i] = 0;
	}
	//Инициализируем массив dsu(вершина i указывает сама на себя).
	for (i = 1; i <= n; i++) dsu[i] = i;

	//Обрабатываем запросы с конца в начало. Если i-ым является запрос ask
	//(mas[0][i] равно 1), то занесем в res[i] единицу при условии, что
	//вершины u и v находятся в одной компоненте связности (и положим res[i] = 0 иначе).
	for (i = k - 1; i >= 0; i--)
	{
		if (mas[0][i]) res[i] = (Repr(mas[1][i]) == Repr(mas[2][i]));
		else Union(mas[1][i], mas[2][i]);
	}
	//Выводим ответы на последовательно поступающие запросы. Если i-ым является
	//запрос ask, то выводим ответ в зависимости от значения res[i].
	for (i = 0; i < k; i++)
		if (mas[0][i]) printf(res[i] ? "YES\n" : "NO\n");

	return 0;
}
