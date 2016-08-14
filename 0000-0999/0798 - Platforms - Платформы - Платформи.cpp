#include <iostream>

using namespace std;

#define MAX 100001

int c, i, n, ptr, y[MAX], e[MAX], p[MAX], res[MAX];

int main() {

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &y[i]);
	e[1] = 0;
	e[2] = abs(y[2] - y[1]);
	p[1] = -1; p[2] = 1;

	//В цикле вычисляем значения ячеек e[i] и p[i](3 ≤ i ≤ n),
	//сравнивая значения e[i – 1] + | yi – yi - 1 | и e[i – 2] + 3 * | yi – yi - 2 | .
	for (i = 3; i <= n; i++)
	{
		int a = e[i - 1] + abs(y[i] - y[i - 1]);
		int b = e[i - 2] + 3 * abs(y[i] - y[i - 2]);
		if (a < b) { e[i] = a; p[i] = i - 1; }
		else
		{
			e[i] = b;
			p[i] = i - 2;
		}
	}

	//В переменной c вычисляем количество платформ, по которым нужно пройти.
	//Для этого на платформу i следует прыгать с платформы p[i].
	ptr = c = 0;
	for (i = n; i > 0; i = p[i]) c++, res[ptr++] = i;

	//Выводим результат. Минимальное количество энергии,
	//которое следует потратить для попадания с первой платформы на n - ую, равно e[n].
	printf("%d\n%d\n1", e[n], c);
	ptr -= 2;
	for (i = ptr; i >= 0; i--) printf(" %d", res[i]);
	printf("\n");
	return 0;
}
