#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define PI acos(-1.0)

int a, b, n;
double s,xc,yc,NewXC, NewYC;
vector<pair<double, double>> v;

double PolarAngle(pair<double, double> p)
{
	double res = atan2(p.second, p.first);
	if (res < 0) res += 2 * PI;
	return res;
}

//Функция f используется при сортировке вершин многоугольника по полярному углу.
int f(pair<double, double> a, pair<double, double> b)
{
	return PolarAngle(a) < PolarAngle(b);
}

//Функция TriangleSquare(a, b, c) вычисляет площадь треугольника, заданного координатами трех вершин.
double TriangleSquare(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
	return abs((b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second)) / 2.0;
}

int main() {
	//Координаты вершин очередного многоугольника запоминаем в векторе пар v.
	while (scanf("%d", &n), n > 2)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		//Найдем координаты точки(NewXC, NewYC), лежащей внутри многоугольника.
		//Поскольку по условию задачи многоугольник выпуклый, то в качестве такой
		//точки можно взять центр тяжести треугольника, образованного точками 0, 1 и 2.
		NewXC = (v[0].first + v[1].first + v[2].first) / 3.0;
		NewYC = (v[0].second + v[1].second + v[2].second) / 3.0;

		//Совершим параллельный перенос всех точек многоугольника на вектор(–NewXC, –NewYC).
		for (int i = 0; i < n; i++) v[i].first -= NewXC, v[i].second -= NewYC;

		//Теперь начало координат(0, 0) находится внутри выпуклого многоугольника.
		//Сортируем вершины многоугольника по полярному углу.
		sort(v.begin(), v.end(), f);

		//Разобъем исходный многоугольник на треугольники с вершинами(0, i, i + 1), i=1..n-1.
		//Для каждого такого тругольника вычисляем его площадь в переменной tempSquare, а также
		//координаты его центра.Последние прибавляем к переменным xc и yc, умножая их предварительно
		//на tempSquare.В переменной s накапливаем площадь всего многоугольника.
		xc = yc = s = 0;
		for (int i = 1; i < n - 1; i++)
		{
			double tempSquare = TriangleSquare(v[0], v[i], v[i + 1]);
			s += tempSquare;
			xc += tempSquare * (v[0].first + v[i].first + v[i + 1].first) / 3.0;
			yc += tempSquare * (v[0].second + v[i].second + v[i + 1].second) / 3.0;
		}
		//Разделив полученные значения xc и yc на s и сдвинув их на вектор(NewXC, NewYC),
		//получим координаты центра масс исходного многоугольника.
		xc = xc / s + NewXC; yc = yc / s + NewYC;
		if (fabs(xc) < 0.00001) xc = 0.0;
		if (fabs(yc) < 0.00001) yc = 0.0;
		printf("%.3lf %.3lf\n", xc, yc);
	}
	return 0;
}
