#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define MAX 10000000

int n, res, m[MAX];
map<int, int> mp;

//Рекурсивное вычисление с запоминанием функции f(n).
int f(int n)
{
	if (n < MAX) return m[n];
	if (mp[n] > 0) return mp[n];
	if (n % 3 == 0) mp[n] = f(n / 3) + 5;
	else mp[n] = f(n - 4) + 2;
	return mp[n];
}

int main() {
	//Положим m[i] = -µ, если значение i Маугли получить не сможет никакими действиями.
	//Вычислим f(i) для i до 10^7 и запомним их в m[i].
	m[0] = -MAX;
	m[1] = 0;
	m[2] = -MAX;
	m[3] = 5;
	m[4] = -MAX;
	m[5] = 2;
	for (int i = 6; i < MAX; i++)
		if (i % 3 == 0) m[i] = min(m[i / 3] + 5, m[i - 4] + 2);
		else m[i] = m[i - 4] + 2;
		cin >> n;
		if (n % 2 == 0)
		{
			cout << "0" << endl;
			return 0;
		}
		res = f(n);
		//Если res окажется меньше 0, то решить задачу невозможно, выводим число 0.
		if (res < 0) res = 0;
		printf("%d\n", res);
		return 0;
}
