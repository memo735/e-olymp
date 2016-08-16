#include <iostream>

using namespace std;

int main() {
	int n, k, res;
	scanf("%d %d", &n, &k);
	res = 1;
	//Пока не пройдет n месяцев моделируем жизнь на планете.
	while (n--)
	{
		//Поедание монстром кроликов.
		if (res > k) res -= k;
		//Размножение кроликов.
		res += res;
	}
	printf("%d\n", res);
	return 0;
}
