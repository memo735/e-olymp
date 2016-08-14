#include <iostream>
#include <string.h>

using namespace std;

char s[100];

//Для каждого теста читаем план улицы в символьный массив s, начиная с первой позиции(для удобства обработки).
int main() {
	int i, n;
	scanf("%d\n", &n);
	while (n--)
	{
		cin >> s + 1;
		int res = 0;
		for (i = 1; i <= strlen(s + 1); i++)
			//Для каждого участка s[i] проверяем, можно ли на нем припарковаться.
			if (s[i] == '-' && s[i + 1] != 'S' && s[i - 1] != 'S' && s[i + 1] != 'B' && s[i + 2] != 'B') res++;

		printf("%d\n", res);
	}
	return 0;
}
