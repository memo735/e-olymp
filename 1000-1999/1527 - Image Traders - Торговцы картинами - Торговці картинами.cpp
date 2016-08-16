#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int i, n, res, m[1 << 15][12][2];
char Price[15][15];

//Функция ones вычисляет количество единиц в бинарном представлении числа n.
int ones(int n)
{
	int c = 0;
	while (n) c++, n = n & n - 1;
	return c;
}

int solve(int mask, int last, int cost)
{
	int temp, i, &ret = m[mask][last][cost];

	//Если значение m[mask][last][cost] уже вычислено (не нулевое), то возвращаем его.
	if (ret) return ret;

	//Вычисляем количество продавцов, которые уже владели картиной (количество единиц в маске mask).
	ret = ones(mask);

	//Перебираем имеющихся продавцов и смотрим, кому продавец с номером last может продать имеющуюся
	//у него картину. Картину можно продать продавцу i, если i - ый бит маски mask равен нулю
	//(у i-го продавца картина на руках еще не была), а также если продавец с номером i готов купить
	//картину у продавца с номером last по цене, не меньшей cost(цене, по которой продавец last приобретал картину).
	for (i = 0; i < n; i++)
		if (!(mask & 1 << i) && Price[last][i] - '0' >= cost)
		{
			temp = solve(mask | 1 << i, i, Price[last][i] - '0');
			if (temp > ret) ret = temp;
		}
	return ret;
}

int main() {

	while (scanf("%d\n", &n) == 1)
	{
		memset(m, 0, sizeof m);

		//Продавцы нумеруются числами от 0 до n – 1.
		for (i = 0; i < n; i++) gets(Price[i]);
		res = solve(1, 0, 0);
		printf("%d\n", res);
	}
	return 0;
}
