#include <iostream>
#include <algorithm>

using namespace std;

double a, b, c, y[101], z[101], EPS = 0.000001;
int n, ptr;

//Добавление треугольника со сторонами (x1, y1, z1) в базу стилей.
//Если его стиль уже встречался ранее, то ничего не делаем. Иначе заносим пару (y/x1, z1/x1) в (y[ptr], z[ptr]).
int add(double x1, double y1, double z1)
{
	y1 = y1 / x1; z1 = z1 / x1;
	for (int i = 0; i < ptr;i++)
		if (fabs(y1 - y[i]) < EPS && fabs(z1 - z[i]) < EPS) return 0;
	y[ptr] = y1; z[ptr] = z1; ptr++;
	return ptr;
}

//Разбиваем треугольник со сторонами (a, b, c) на два со сторонами (a, m, c / 2) и (b, m, c / 2).
//Перед разбиением сортируем стороны в неубывающем порядке.Рекурсивно запускаем разбиение полученных треугольников.
void triangle(double a, double b, double c)
{
	double temp[3], m;
	temp[0] = a; temp[1] = b;  temp[2] = c;
	sort(temp, temp + 3);
	if (!add(temp[0], temp[1], temp[2])) return;
	m = sqrt(2 * temp[0] * temp[0] + 2 * temp[1] * temp[1] - temp[2] * temp[2]) / 2;
	triangle(temp[0], m, temp[2] / 2);
	triangle(temp[1], m, temp[2] / 2);
}

int main() {
	scanf("%d", &n);
	for (int test = 1; test <= n; test++)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		ptr = 0;
		triangle(a, b, c);
		printf("Triangle %d: %d\n", test, ptr);
	}
	return 0;
}
