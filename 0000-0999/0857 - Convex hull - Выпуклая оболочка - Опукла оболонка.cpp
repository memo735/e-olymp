#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point
{
public:
	int x, y;
	Point(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
	}
	double len2() const { return x*x + y*y; }
};

Point operator+ (Point a, Point b)
{
	return Point(a.x + b.x, a.y + b.y);
}

Point operator- (Point a, Point b)
{
	return Point(a.x - b.x, a.y - b.y);
}

vector<Point> v, hull;
int i, n, cur, a, b;
double p;

int TurnLeft(Point a, Point b, Point c)
{
	Point p = b - a, q = c - b;
	return p.x * q.y > q.x * p.y;
}

//Сортируем точки по возрастанию полярного угла относительно центральной v[0].
//Точка b имеет больший полярный угол чем а (то есть a < b), если поворот(v[0], a, b) является левым.
//Если все три точки v[0], a, b коллинеарны, то a < b если только расстояние от начала координат до a меньше чем до b.
//В случае правого поворота(v[0], a, b) компаратор f должен вернуть 0.
int f(Point a, Point b)
{
	Point p = a - v[0], q = b - a;
	if (p.x * q.y == q.x * p.y) return a.len2() < b.len2();
	return p.x * q.y > q.x * p.y;
}

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back(Point(a, b));
	}
	for (i = 1; i < n; i++)
	{
		if (v[i].x < v[0].x) swap(v[i], v[0]);
		if (v[i].x == v[0].x && v[i].y < v[0].y) swap(v[i], v[0]);
	}
	sort(v.begin() + 1, v.end(), f);
	v.push_back(v[0]); n++;

	//v[0] содержит самую левую нижнюю точку. Параллельный перенос
	//координат (так чтобы v[0] стало центром координат) можно не делать.
	for (cur = 1, i = 2; i < n; i++)
	{
		while (cur > 0 && !TurnLeft(v[cur - 1], v[cur], v[i])) cur--;
		v[++cur] = v[i];
	}
	for (i = 0; i < cur; i++) p += sqrt(1.0*(v[i + 1] - v[i]).len2());
	printf("%.1lf\n", p);
	return 0;
}
