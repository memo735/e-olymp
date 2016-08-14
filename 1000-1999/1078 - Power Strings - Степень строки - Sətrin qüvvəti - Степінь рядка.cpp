#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> p;
char s[1000001];
int n, k, len;

//Функция MaxBorderArray строит префикс - функцию строки s.
vector<int> MaxBorderArray(char *s)
{
	int i, j;
	vector<int> p(len, 0);
	p[0] = 0;
	for (i = 1; i < len; i++)
	{
		j = p[i - 1];
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) p[i] = j + 1;
		else p[i] = 0;
	}
	return p;
}

int main() {
	//Читаем входную строку s, вычисляем ее длину len.Вычисляем в массиве p префикс - функцию.
	while (gets(s) && strcmp(s, "."))
	{
		len = strlen(s);
		p = MaxBorderArray(s);

		//Вычисляем разницу между длиной слова и длиной самого длинного префикса строки s, совпадающей с ее суффиксом.
		k = len - p[len - 1];

		//Если длина слова len не делится на полученную разницу k, то входная строка s
		//не является степенью никакой строки. Иначе степень строки s равна len / k.
		if (len % k) n = 1;
		else n = len / k;
		printf("%d\n", n);
	}
	return 0;
}
