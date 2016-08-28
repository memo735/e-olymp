#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10001

int a, b, c, d, i, len, start;
char s[MAX];

int main() {
	//Читаем строку, начиная с 4-ой позиции строки s.
	gets(s + 4); len = strlen(s + 4);

	//Вычисляем индекс начала строки.Дополняем первую четверку нулями.
	start = (len % 4) ? len % 4 : 4;
	for (i = start; i < 4; i++) s[i] = '0';
	//Обрабатываем последовательно четверки символов. Выводим
	//соответствующий символ в шестнадцатеричной системе счисления.
	for (i = start; i <= len; i += 4)
	{
		sscanf(s + i, "%1d%1d%1d%1d", &a, &b, &c, &d);
		printf("%X", 8 * a + 4 * b + 2 * c + d);
	}
	printf("\n");
	return 0;
}
