#include <iostream>
#include <algorithm>

using namespace std;

int cycle_length(int n)
{
	int cnt;
	for (cnt = 1; n != 1; cnt++)
		if (n % 2) n = 3 * n + 1;
		else n = n / 2;
		return cnt;
}

//Функция check вычисляет длину максимального цикла для чисел от i до j простым перебором.
int check(int i, int j)
{
	int mx = 0;
	for (; i <= j; i++) mx = max(mx, cycle_length(i));
	return mx;
}

int main() {
	//Входное значение i может быть больше j, в таком случае следует
	//поменять i и j местами.Вычисляем и выводим максимальную длину цикла.
	int i, j;
	while (scanf("%d %d", &i, &j) == 2)
	{
		int tmp, itemp = i, jtemp = j;
		if (i > j) tmp = i, i = j, j = tmp;
		printf("%d %d %d\n", itemp, jtemp, check(i, j));
	}
	return 0;
}
