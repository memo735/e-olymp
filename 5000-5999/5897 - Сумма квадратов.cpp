#include <iostream>

using namespace std;

#define MOD 1000000009

long n, m, res, temp;

//Функция sum вычисляет сумму квадратов 1^2 + 2^2 + … + n^2 по формуле, приведенной в анализе задачи.
//Чтобы избежать переполнения при умножении, сначала сократим на 6 числитель дроби, после чего совершим умножение.
long sum(long n)
{
	long a = n % MOD;
	long b = (n + 1) % MOD;
	long c = (2 * n + 1) % MOD;

	//Поскольку n или n + 1 делится на 2, то разделим четный множитель на 2.
	a % 2 == 0 ? a = a / 2 : b = b / 2;

	//Один из множителей a = n, b = n + 1 или c = 2n + 1 обязательно делится на 3, разделим его на 3.
	if (a % 3 == 0) a = a / 3;
	else b % 3 == 0 ? b = b / 3 : c = c / 3;

	//Найдем произведение оставшихся после сокращения множителей.
	return a * b % MOD * c % MOD;
}

int main() {
	scanf("%ld %ld", &n, &m);
	if (n > m) swap(n, m);
	if (m < 0) { temp = n; n = -m; m = -temp; }
	if (n >= 0) res = (sum(m) - sum(n - 1) + MOD) % MOD;
	else res = (sum(m) + sum(-n)) % MOD;
	printf("%ld\n", res);
	return 0;
}
