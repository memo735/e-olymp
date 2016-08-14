#include <iostream>
#include <algorithm>

using namespace std;

class Point
{
public:
	int x;
	char c; // 'b' – начало отрезка, 'e' – конец отрезка
	Point()
	{
		x = 0;
		c = '-';
	}
	Point(int x, char c) : x(x), c(c) {}
};
Point p[20001];

//Функция сортировки точек по их абсциссам.
int f(Point a, Point b)
{
	return a.x < b.x;
}

int i, n, x, y, len, depth;

int main() {
	scanf("%d", &n);
	for (i = 0; i < 2 * n; i += 2)
	{
		scanf("%d %d", &x, &y);
		p[i] = Point(x, 'b');
		p[i + 1] = Point(y, 'e');
	}

	//Сортируем точки по абсциссам.
	sort(p, p + 2 * n, f);

	//Моделируем движение заметающей прямой слева направо.
	depth = len = 0;
	for (i = 0; i < 2 * n - 1; i++) // двигаемся по отрезку [p[i]...p[i+1]
	{
		if (p[i].c == 'b') depth++;
		if (p[i].c == 'e') depth--;
		if (depth > 0) len += p[i + 1].x - p[i].x;
	}
	printf("%d\n", len);
	return 0;
}
