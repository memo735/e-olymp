#include <iostream>
#include <string.h>

using namespace std;

#define MAX 2000

int ptr, n, i, m[MAX], p[801][MAX], pt[MAX];

void mult(int n)
{
	int i, carry = 0, temp, res[MAX];
	for (i = 0; i <= ptr; i++)
	{
		temp = carry + m[i] * n;
		res[i] = temp % 10;
		carry = temp / 10;
	}
	while (carry > 0)
	{
		res[++ptr] = carry % 10;
		carry /= 10;
	}
	memcpy(m, res, sizeof res);
	if (n % 2)
	{
		i = 0;
		while (!m[i]) m[i++] = 9;
		m[i]--;
	}
	else
	{
		i = 0;
		while (m[i] == 9) m[i++] = 0;
		m[i]++;
	}
}

int main() {
	//Для каждого i (2 < i < 800) вычисляем значение f(i) в массиве m и сохраняем его в ячейке p[i].
	memset(m, 0, sizeof m);
	ptr = 0;
	for (i = 2; i <= 800; i++)
	{
		mult(i);
		memcpy(p[i], m, sizeof m);
		pt[i] = ptr;
	}
	//Для каждого входного значения n выводим содержимое p[n].
	while (scanf("%d", &n), n != -1)
	{
		if (n == 1) printf("0");
		else for (i = pt[n]; i >= 0; i--) printf("%d", p[n][i]);
		printf("\n");
	}
	return 0;
}
