#include <iostream>
#include <algorithm>

using namespace std;

int MAX = 2147483647;
int MIN = -2147483648;

int main() {
	int prev, cur;
	scanf("%d", &prev);
	while (scanf("%d", &cur) == 1)
	{
		//Если значение cur не принадлежит интервалу[min; max], то искомого пути в дереве не существует.
		if (cur < MIN || cur > MAX)
		{
			puts("NO");
			return 0;
		}
		//Изменяем границы интервала[min; max].
		if (cur > prev) MIN = prev;
		else MAX = prev;
		prev = cur;
	}
	//Если все числа обработаны корректно, то искомый путь в дереве существует.
	puts("YES");
	return 0;
}
