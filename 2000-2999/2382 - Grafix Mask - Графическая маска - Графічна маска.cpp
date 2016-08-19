#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int i, j, k, n, Top, Left, Right, Down, ptr, m[400][600];
vector<int> res;

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
} _Stack[240001];

//Нерекурсивная реализация поиска в глубину из точки(i, j).
//Функция dfs возвращает размер дырки, которой принадлежит точка(i, j).
int dfs(int i, int j)
{
	int res = 0;
	_Stack[ptr++] = Point(i, j);
	Point node;
	while (ptr > 0)
	{
		node = _Stack[--ptr];
		if (m[node.x][node.y]) continue;
		m[node.x][node.y] = 1; res++;
		if (node.x < 399 && !m[node.x + 1][node.y]) _Stack[ptr++] = Point(node.x + 1, node.y);
		if (node.x > 0 && !m[node.x - 1][node.y]) _Stack[ptr++] = Point(node.x - 1, node.y);
		if (node.y < 599 && !m[node.x][node.y + 1]) _Stack[ptr++] = Point(node.x, node.y + 1);
		if (node.y > 0 && !m[node.x][node.y - 1]) _Stack[ptr++] = Point(node.x, node.y - 1);
	}
	return res;
}

//Просматриваем слой слева направо и сверху вниз. Для каждой точки(j, k), не покрытой никаким
//прямоугольником (m[j][k] = 0), запускаем поиск в глубину dfs(j, k). Размеры дырок сохраняем
//в массиве res.По окончании работы функции sortedAreas сортируем массив дырок res и возвращаем его.
vector<int> sortedAreas()
{
	vector<int> res;
	int j, k;
	for (ptr = j = 0; j < 400; j++)
		for (k = 0; k < 600; k++)
			if (!m[j][k]) res.push_back(dfs(j, k));
	sort(res.begin(), res.end());
	return res;
}

int main() {
	//Считываем прямоугольники и наносим их на маскирующий слой. Таким образом, если точка (j, k) остается
	//не покрытой никаким прямоугольником, то m[j][k] = 0. Иначе m[j][k] устанавливается равным 1.
	while (scanf("%d", &n) == 1)
	{
		memset(m, 0, sizeof m);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d %d %d", &Top, &Left, &Down, &Right);
			for (j = Top; j <= Down; j++)
				for (k = Left; k <= Right; k++) m[j][k] = 1;
		}
		//При помощи нерекурсивного поиска в глубину вычисляем размеры всех дырок и выводим их в возрастающем порядке.
		res = sortedAreas();
		for (i = 0; i < res.size(); i++) printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}
