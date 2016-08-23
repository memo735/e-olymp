#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point
{
public:
	long x, y;
	Point(long x = 0, long y = 0) : x(x), y(y) {};
	long len2() const { return x*x + y*y; }
};

Point operator+ (Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }

Point operator- (Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }

vector<Point> v, hull;
int i, j, n, cur;
long a, b, d, diam;

//Компаратор точек a и b по их полярному углу. Если две точки имеют
//одинаковый полярный угол, то сравниваем их расстояния от начала координат.
int f(Point a, Point b)
{
	Point q = a - v[0], w = b - a;
	if (q.x * w.y == w.x * q.y) return a.len2() < b.len2();
	return q.x * w.y > w.x * q.y;
}

//Функция TurnLeft возвращает истину, если точки a, b, c образуют левый поворот.
int TurnLeft(Point a, Point b, Point c)
{
	Point q = b - a, w = c - b;
	return q.x * w.y > w.x * q.y;
}

//Функция dist возвращает квадрат расстояния между точками i и j.
long dist(int i, int j) { return (v[j] - v[i]).len2(); }

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a, &b);
		v.push_back(Point(a, b));
	}
	//Заносим в v[0] самую левую точку.Если таких несколько, то из самых левых точек выбираем нижнюю.
	for (i = 1; i < n; i++)
	{
		if (v[i].x < v[0].x) swap(v[i], v[0]);
		if (v[i].x == v[0].x && v[i].y < v[0].y) swap(v[i], v[0]);
	}
	//Сортируем точки по полярному углу.Добавим в конец первую точку.
	sort(v.begin() + 1, v.end(), f);  v.push_back(v[0]); n++;
	//Запускаем обход Грехема. В ячейках v[0..cur] сохраняются точки,
	//принадлежащие выпуклой оболочке.При этом v[cur] = v[0].
	for (cur = 1, i = 2; i < n; i++)
	{
		while (cur > 0 && !TurnLeft(v[cur - 1], v[cur], v[i])) cur--;
		v[++cur] = v[i];
	}
	//Для удобства будем искать квадрат максимального расстояния diam между парой точек
	//на выпуклой оболочке. Двумя указателями будут i и j, содержащие номера точек.
	diam = 0;
	for (i = 0, j = 1; i < cur; i++)
	{
		//Двигаем указатель j, пока расстояние от i до j увеличивается(пока dist(i, j) ≤ dist(i, j + 1)).
		while (j < cur && dist(i, j) <= dist(i, j + 1)) j++;
		//Вычисляем квадрат расстояния между точками i и j и пересчитываем квадрат диаметра точек diam.
		diam = max(diam, dist(i, j));
	}
	printf("%.12lf\n", sqrt(diam));
	return 0;
}
