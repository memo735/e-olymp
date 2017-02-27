#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define MOD 1000000000
typedef vector<long> vi;
typedef vector<vector<long> > vvi;
vi b;
vvi m;

//Умножение матрицы a на матрицу b.Все вычисления производятся по модулю mod.
vvi mult(vvi a, vvi b, int mod)
{
	int i, j, k, s, n = a.size();
	vvi c(n, vi(n));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			for (s = k = 0; k < n; k++) s = (s + a[i][k] * b[k][j]) % mod;
			c[i][j] = s;
		}
	return c;
}

//Умножение матрицы a на вектор b.
vi mult(vvi a, vi b, int mod)
{
	int i, j, n = a.size();
	vi c(n, 0);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i] = (c[i] + a[i][j] * b[j]) % mod;
	return c;
}

//Возведение матрицы a в степень k.
vvi pow(vvi a, int k, long mod)
{
	int i, n = a.size();
	vvi res(n, vi(n, 0));
	for (i = 0; i < n; i++) res[i][i] = 1;
	while (k > 0)
	{
		if (k % 2) res = mult(res, a, mod);
		a = mult(a, a, mod);
		k /= 2;
	}
	return res;
}

int main() {
	int i, k, n, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &k);
		b.assign(k, 0);
		//Изначально положим b = (bk, bk - 1, …, b2, b1).
		for (i = k - 1; i >= 0; i--) scanf("%lld", &b[i]);
		m.assign(k, vector<long>(k, 0));
		//Значения ci считываем прямо в первую строку матрицы m.Заполняем остальные строки матрицы m.
		for (i = 0; i < k; i++) scanf("%lld", &m[0][i]);
		for (i = 1; i < k; i++) m[i][i - 1] = 1;
		//Если n ≥ k, то производим вычисления по указанной в анализе задачи формуле.
		scanf("%d", &n);
		if (n >= k)
		{
			m = pow(m, n - k, MOD);
			b = mult(m, b, MOD);
			printf("%ld\n", b[0]);
		}
		//Если n < k, то ответ берем из соответствующей ячейки массива b.
		else printf("%ld\n", b[k - n]);
	}
	return 0;
}
