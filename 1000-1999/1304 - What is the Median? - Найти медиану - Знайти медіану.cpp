#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n, pos, len = 0;

int main() {
	//Для каждого нового числа n при помощи функции lower_bound находим позицию pos,
	//на которую можно вставить число n так, чтобы не нарушалось свойство отсортированности массива.
	while (scanf("%d", &n) == 1)
	{
		len++;
		pos = lower_bound(v.begin(), v.end(), n) - v.begin();

		//Вставляем число n в позицию pos.
		v.insert(v.begin() + pos, n);

		//В зависимости от длины последовательности выводим значение ее медианы.
		//Последняя равна v[len / 2], если количество чисел в последовательности нечетно и (v[len / 2] + v[len / 2 – 1]) / 2 иначе.
		if (len & 1) printf("%d\n", v[len / 2]);
		else printf("%d\n", (v[len / 2] + v[len / 2 - 1]) / 2);
	}
	return 0;
}
