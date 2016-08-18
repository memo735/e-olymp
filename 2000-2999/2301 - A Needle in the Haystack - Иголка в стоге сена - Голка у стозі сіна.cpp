#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10001

char ch, word[MAX];
int i, j, len, p[MAX];

//Функция MaxBorderArray вычисляет в массиве p префикс - функцию строки s.
void MaxBorderArray(char *s)
{
	len = strlen(s);
	p[0] = 0;
	for (i = 1; i < len; i++)
	{
		j = p[i - 1];
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
}

//Функция kmp реализует алгоритм Кнута - Морриса - Пратта и выводит все
//начальные позиции совпадений. Шаблон (иголка) находится в массиве word.
//Текст имеет длину около 10 миллионов символов, считывается посимвольно.
void kmp()
{
	scanf("%c", &ch);
	for (i = j = 0; ch != '\n'; i++)
	{
		while (j && ch != word[j]) j = p[j - 1];
		if (ch == word[j]) j++;

		//Если найдено совпадение – выводим положение его первого символа.
		if (j == len) printf("%d\n", i - j + 1);
		scanf("%c", &ch);
	}
}

int main() {
	//Функция MaxBorderArray вычисляет префикс - функцию, которая используется в КМП.
	scanf("%d\n", &len);
	while (1)
	{
		gets(word);
		MaxBorderArray(word);
		kmp();
		if (scanf("%d\n", &len) != 1) break;
		printf("\n");
	}
	return 0;
}
