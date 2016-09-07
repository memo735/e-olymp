#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

#define MAX 1001
char Pa[MAX], Pb[MAX], w[MAX];
int a, b, c, d, t, x, y, x2, y2, disc;
double res;

//Используется при обработке входных данных. Подсчитываем количество
//букв 'a' и 'b' в строке s соответственно в переменных a и b.
void CountAB(char *s, int &a, int &b)
{
	for (int i = a = b = 0; i < strlen(s); i++) (s[i] == 'a' ? a : b)++;
}

int main() {
	//Для каждого теста читаем входные данные. В каждой
	//входной строке подсчитываем количество букв 'a' и 'b'.
	scanf("%d\n", &t);
	while (t--)
	{
		cin >> Pa; CountAB(Pa, a, b);
		cin >> Pb; CountAB(Pb, c, d);
		cin >> w;  CountAB(w, x, y);

		//Вычислим (x2, y2) = ((a, b), (c, d))*(x, y).
		x2 = a * x + c * y;
		y2 = b * x + d * y;

		//Если вектора (x, y) и (x2, y2) коллинеарны (тогда x / x2 = y / y2 или y*x2 = x*y2), то вектор (x, y)
		//является собственным, и ответ равен x2 / x или y2 / y (в зависимости от того, равно ли x нулю).
		if (y * x2 == x * y2) res = x ? 1.0 * x2 / x : 1.0 * y2 / y;
		else //Если a = d = 0, а b = c, то большее собственное значение матрицы  равно b.
		{
			if (!a && !d) {
				if (b == c) res = b;
				else
				{
					printf("-\n");
					continue;
				}
			}
			else
			{
				//Находим собственные значения матрицы A = ((a, b), (c, d)), решая уравнение
				//| A - λE | = 0. Вычисляем дискриминант disc квадратного уравнения.
				disc = (a - d) * (a - d) + 4 * b * c;
				//Больший корень (собственное значение) равен
				res = (a + d + sqrt(disc)) / 2.0;
			}
		}
		printf("%.12lf\n", res);
	}
	return 0;
}
