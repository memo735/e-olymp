#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int f(int a, int b)
{
	return a > b;
}

int main() {
	//Вектор t содержит время в днях, за которые вырастут имеющиеся деревья. Поскольку 
	//дни нумеруются с 1, то и в массиве t числа будем хранить начиная с 1 индекса.
	vector<int> t;
	int i, n, res = 0;
	scanf("%d", &n);
	t.resize(n + 1);
	for (i = 1; i <= n; i++) scanf("%d", &t[i]);
	sort(t.begin() + 1, t.end(), f);
	
	//Вычисляем самый ранний день res, в который можно провести вечеринку.
	for (i = 1; i <= n; i++) res = max(res, i + t[i] + 1);
	printf("%d\n", res);
	return 0;
}
