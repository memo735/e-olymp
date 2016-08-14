#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double s = 0, x, y, x1, y1;
	scanf("%lf %lf", &x, &y);
	while (scanf("%lf %lf %lf %lf", &x, &y, &x1, &y1) == 4) s += sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y));

	//Длина пути, которую пройдет снегоуборочная машина, равна 2s метров.
	//Поскольку скорость машины при уборке снега равна 20 км / час = (20 * 1000 / 60) м / мин,
	//то общее время ее работы составит = минут.

	int time = (int)(3 * s / 500 + 0.5);
	printf("%d:%d\n", time / 60, time % 60);
	return 0;
}
