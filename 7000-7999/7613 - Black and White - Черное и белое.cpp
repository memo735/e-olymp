#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char s[4][3000];

int main() {
	int b, i, w, z;
	memset(s, 0, sizeof s);
	scanf("%d %d", &b, &w);
	//Вычисляем и выводим размер картины.
	z = max(b, w) * 2;
	printf("%d %d\n", 4, z);
	//Строим первую строку.
	for (i = 0; i < w - 1; i++)
	{
		s[0][2 * i] = '.';
		s[0][2 * i + 1] = '@';
	}
	for (i = 2 * w - 2; i < z; i++) s[0][i] = '@';
	//Строим вторую и третью строку.
	for (i = 0; i < z; i++)
	{
		s[1][i] = '@';
		s[2][i] = '.';
	}
	//Строим четвертую строку.
	for (i = 0; i < b - 1; i++)
	{
		s[3][2 * i] = '.';
		s[3][2 * i + 1] = '@';
	}
	for (i = 2 * b - 2; i < z; i++) s[3][i] = '.';
	for (i = 0; i < 4; ++i) puts(s[i]);
	return 0;
}
