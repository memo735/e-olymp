#include <iostream>
#include <algorithm>

using namespace std;

int i, j, n, val, v[250];

int main() {
	//Читаем значение n. Генерируем в цикле по i все 2n – 1 подмножеств (кроме пустого).
	scanf("%d", &n);
	for (i = 1; i < 1 << n; i++)
	{
		for (val = j = 0; j < n; j++)
			if (i & (1 << j)) val = val * 10 + j + 1;
		v[i] = val;
	}
	//Отсортируем подмножества по возрастанию чисел, их представляющих.
	sort(v, v + (1 << n));
	//Выводим подмножества в требуемом порядке.
	for (i = 1; i < 1 << n; i++) printf("%d\n", v[i]);
	return 0;
}
