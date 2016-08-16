#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
char s[1000001];
int len, res;

//Функция z строит и возвращает z - функцию для строки s.
vector<int> z(char *s)
{
	int i, l, r;
	vector<int> z(len, 0);
	for (i = 1, l = 0, r = 0; i < len; i++)
	{
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < len && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	//Читаем входную строку s, вычисляем ее длину len.
	//Строим z - функцию при помощи функции z.
	//Находим длину res наибольшего блока строки s и выводим ее.
	gets(s);
	len = strlen(s);
	v = z(s); res = 0;
	for (int i = 1; i < len; i++) if (res < v[i]) res = v[i];
	printf("%d\n", res);
	return 0;
}
