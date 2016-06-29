#include <stdio.h>

long mas[30];

long long get(char ch)
{
	char temp;
	long long ret = 0;
	do
	{
		scanf("%c", &temp);
		if (temp != ch) ret = ret * 10 + (temp - 48);
	} while (temp != ch);
	return ret;
}
long get_mas(long long osnova, long long n)
{
	long len = 0;
	while (n)
	{
		mas[len] = n % osnova;
		n /= osnova;
		len++;
	}
	return len;
}
void out_mas(long len)
{
	for (int i = len - 1; i >= 0; i--)
		if (mas[i] < 10) printf("%d", mas[i]);
		else printf("%c", char(mas[i] + 55));
}
int main()
{
	long long D, M, Y;
	D = get('/');
	M = get('/');
	Y = get('\n');
	out_mas(get_mas(D + 1, D));
	printf("/");
	out_mas(get_mas(D + 1, M));
	printf("/");
	out_mas(get_mas(D + 1, Y));
	printf("\n");
}
