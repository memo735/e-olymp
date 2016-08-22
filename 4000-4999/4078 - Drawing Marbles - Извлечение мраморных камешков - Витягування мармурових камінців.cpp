#include <iostream>

using namespace std;

int i, j, n, col, total, colors[50];
double p, res;

int main() {
	while (scanf("%d %d", &col, &n) == 2)
	{
		//Вычисляем общее количество камешков в переменной total.
		for (i = total = 0; i < col; i++) {
			scanf("%d", &colors[i]);
			total += colors[i];
		}
		for (res = i = 0; i < col; i++)
		{
			if (n > colors[i]) continue;
			//В переменной p вычисляем вероятность вынуть из коробки все
			//n камешков цвета i + 1 (цвета у нас имеют номера от 1 до col).
			for (p = 1, j = 0; j < n; j++) p *= 1.0 * (colors[i] - j) / (total - j);
			res += p;
		}
		printf("%.4lf\n", res);
	}
	return 0;
}
