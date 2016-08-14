#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

char s[400001], ss[200001];

//Функция z вычисляет и возвращает z - функцию.
vector<int> z(char *s)
{
	int i, l, r, n = strlen(s);
	vector<int> z(n, 0);
	for (i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	//Читаем входную строку, вычисляем ее длину len.
	//Копируем строку s в ss. Обращаем ее. 
	//Совершаем конкатенацию входной строки с ее обращенной.
	int n; scanf("%d\n", &n);
	gets(s);
	int len = strlen(s);
	strcpy(ss, s);
	reverse(ss, ss + len);
	strcat(s, ss);

	//Вычисляем z - функцию построенной строки.
	vector<int> res = z(s);

	//Выводим ответ – значения Z[2 * len – 1], Z[2 * len – 2], …, Z[len]..
	int i = res.size() - 1;
	printf("%d", res[i]);
	for (--i; i >= len; i--) printf(" %d", res[i]);
	printf("\n");
	return 0;
}
