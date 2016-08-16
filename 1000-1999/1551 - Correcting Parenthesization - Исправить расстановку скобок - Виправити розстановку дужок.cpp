#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int m[51][51], res;
char s[51];

int enc(char c, char d)
{
	string p = "([{)]}";
	//Функция возвращает 2, если c является закрывающейся скобкой, а d открывающейся.
	if (p.find(c) / 3 > 0 && p.find(d) / 3 < 1) return 2;

	//Функция возвращает 0, если c и d являются соответствующими скобками. Если они
	//стоят не в правильном порядке, то функция вернет значение 2 в предыдущей строке.
	if (p.find(c) % 3 == p.find(d) % 3 && c != d) return 0;
	return 1;
}

//Функция f(i, j) возвращает наименьшее количество символов, которое можно
//изменить так, чтобы подстрока s[]is[i + 1]…s[j - 1]s[j] стала правильной.
int f(int i, int j)
{
	int k;
	if (i > j) return 0;
	if (m[i][j] >= 0) return m[i][j];
	int r = f(i + 1, j - 1) + enc(s[i], s[j]);
	for (k = i + 1; k < j; k += 2) r = min(r, f(i, k) + f(k + 1, j));
	return m[i][j] = r;
}

int main() {
	while (gets(s))
	{
		memset(m, -1, sizeof m);
		res = f(0, strlen(s) - 1);
		printf("%d\n", res);
	}
	return 0;
}
