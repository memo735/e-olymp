#include <iostream>
#include <string.h>

using namespace std;

#define INF 0x3F3F3F3F3F3F3F3F
#define MAX 11

string Answer, Stroka[11] = { "0","1","2","3","4","5","6","7","8","9","10" };
long m[MAX][MAX], s[MAX][MAX], p[MAX];

//Функция Mult находит минимальное количество умножений, необходимое для вычисления
//Aij = A[i] * A[i + 1] * … * A[j - 1] * A[j], которое сохраняем в ячейке m[i, j].
long Mult(int i, int j)
{
	int k;
	long temp;
	if (m[i][j] == INF)
		for (k = i; k <= j - 1; k++)
		{
			temp = Mult(i, k) + Mult(k + 1, j) + p[i - 1] * p[k] * p[j];
			if (temp < m[i][j])
			{
				m[i][j] = temp;
				s[i][j] = k;
			}
		}
	return m[i][j];
}

//Функция Print(i, j) выводит оптимальное произведение матриц
//A[i] * A[i + 1] * … * A[j - 1] * A[j] согласно формату вывода.
string Print(int i, int j)
{
	if (i == j) return "A" + Stroka[i];
	return "(" + Print(i, s[i][j]) + " x " + Print(s[i][j] + 1, j) + ")";
}

int main() {
	int n, cs = 1;
	while (scanf("%d", &n), n)
	{
		//Присвоим всем ячейкам массива m значения «бесконечность».
		memset(m, 0x3F, sizeof m);

		//Читаем размеры входных матриц, сохраняем их в массиве p.Положим m[i, i] = 0.
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &p[i - 1], &p[i]);
			m[i][i] = 0;
		}
		//Вычисляем результат – ищем оптимальное произведение матриц A1 * A2 * … * An - 1 * An.
		Mult(1, n);

		//Выводим номер теста cs. Если n = 1, то перемножать нечего и следует вывести строку "(A1)".
		//Иначе вызываем функцию Print(1, n), которая возвращает строку, содержащую
		//последовательность оптимального произведения матриц.
		printf("Case %d: ", cs++);
		if (n == 1) Answer = "(A1)";
		else Answer = Print(1, n);
		printf("%s\n", Answer.c_str());
	}
	return 0;
}
