#include <iostream>

using namespace std;

int i, j, n, inv, res, fact[13], m[13];

int main() {
	//Читаем входную перестановку в массив m.
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &m[i]);

	//Заполняем массив факториалов чисел.
	fact[0] = 1;
	for (i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
	for (res = 0, i = 1; i <= n; i++)
	{
		//Для заданного значения i в переменной inv подсчитываем
		//количество di таких элементов m[j], для которых i < j и m[i] > m[j].
		for (inv = 0, j = i + 1; j <= n; j++) if (m[j] < m[i]) inv++;
		//Добавляем к результату значение di * (n – i)!
		res += inv * fact[n - i];
	}
	printf("%d\n", res + 1);
	return 0;
}
