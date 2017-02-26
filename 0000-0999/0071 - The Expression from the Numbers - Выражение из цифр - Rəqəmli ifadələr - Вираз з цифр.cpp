#include <iostream>
#include <set>

using namespace std;

set<int> s[10];
set<int>::iterator it1, it2;
int i, j, n, d, val;

int main() {
	scanf("%d %d", &n, &d);
	//Заносим в s[i] число, состоящее из i цифр d.
	//Заносим как положительное число, так и соответствующее ему отрицательное.
	val = 0;
	for (i = 1; i <= n; i++)
	{
		val = 10 * val + d;
		s[i].insert(val);
		s[i].insert(-val);
	}
	//Строим множество s[i].
	for (i = 2; i <= n; i++)
		for (j = 1; j + j <= i; j++)
			//Перебираем все элементы x из s[j].
			for (it1 = s[j].begin(); it1 != s[j].end(); ++it1)
				//Перебираем все элементы y из s[i – j].
				for (it2 = s[i - j].begin(); it2 != s[i - j].end(); ++it2)
				{
					int x = *it1, y = *it2;
					//Совершаем все возможные операции над аргументами x и y, результат заносим в s[i].
					//Поскольку мы работаем со множествами, то дублирующие элементы сохраняться не будут.
					s[i].insert(x + y);
					s[i].insert(x * y);
					if (y != 0 && x % y == 0) s[i].insert(x / y);
					if (x != 0 && y % x == 0) s[i].insert(y / x);
					s[i].insert(x - y);
					s[i].insert(y - x);
				}

	//Ищем наименьшее число res, которого нет во множестве s[n].
	int res = 1;
	while (s[n].find(res) != s[n].end()) res++;
	printf("%d\n", res);
	return 0;
}
