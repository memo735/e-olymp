#include <iostream>

using namespace std;

#define MAX 300000
long m[MAX];

//Функция calc вычисляет значение An.
long calc(long n, long p, long q, long x, long y)
{
	long temp;
	//Если n <= 0, то An = 1.
	if (n <= 0) return 1;

	//Если n < 300000 и значение m[n] уже вычислено(не равно нулю), то возвращаем его.
	if (n < MAX && m[n]) return m[n];

	//Совершаем рекурсивное вычисление значения An согласно приведенной в условии задачи формулы.
	temp = calc(n / p - x, p, q, x, y) + calc(n / q - y, p, q, x, y);

	//Если n < 300000, то запоминаем An в массиве m чтобы избежать в дальнейшем повторных вычислений.
	if (n < MAX) m[n] = temp;
	return temp;
}

int main() {
	long n, p, q, x, y, res;
	scanf("%ld %ld %ld %ld %ld", &n, &p, &q, &x, &y);
	res = calc(n, p, q, x, y);
	printf("%ld\n", res);
	return 0;
}
