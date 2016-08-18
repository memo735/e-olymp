#include <iostream> 
#include <algorithm>

using namespace std;

#define MAX 40001

int i, n, h, w, dx, dy, x[MAX], y[MAX];

int main() {
	scanf("%d %d %d", &w, &h, &n);
	for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

	//Добавим две башни с координатами(0, 0) и(w + 1, h + 1), увеличим количество башен n на 2.
	x[n] = y[n] = 0;
	x[n + 1] = w + 1; y[n + 1] = h + 1;
	n += 2;

	//Сортируем массив абсцисс и ординат.
	sort(x, x + n);
	sort(y, y + n);

	//Ищем максимальное расстояние dx между соседними абсциссами.
	dx = 0;
	for (i = 0; i < n - 1; i++) if (x[i + 1] - x[i] > dx) dx = x[i + 1] - x[i];

	//Ищем максимальное расстояние dy между соседними ординатами.
	dy = 0;
	for (i = 0; i < n - 1; i++) if (y[i + 1] - y[i] > dy) dy = y[i + 1] - y[i];

	//Выводим размер максимального незащищенного прямоугольника.
	printf("%d\n", (dx - 1) * (dy - 1));
	return 0;
}
