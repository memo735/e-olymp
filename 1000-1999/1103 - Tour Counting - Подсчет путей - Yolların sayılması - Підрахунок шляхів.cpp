#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vector<string> g;
char line[50];
int n, k, m, res;

//Сложение матриц a и b по модулю mod.
vvi add(vvi &a, vvi &b, int mod)
{
	int i, j, n = a.size();
	vvi c(n, vi(n));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) c[i][j] = (a[i][j] + b[i][j]) % mod;
	return c;
}

//Умножение матриц a и b по модулю mod.
vvi mult(vvi &a, vvi &b, int mod)
{
	int i, j, k, s, n = a.size();
	vvi c(n, vi(n));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			for (s = k = 0; k < n; k++) s = (s + (long)a[i][k] * b[k][j]) % mod;
			c[i][j] = s;
		}
	return c;
}

//Вычисление матрицы a^k по модулю mod.
vvi pow(vvi &a, int k, int mod)
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

//Вычисление суммы sum(k) = a + a^2 + a^3 + … + a^k.
vvi sum(vvi a, int k, int mod)
{
	if (k == 1) return a;
	if (k % 2)
	{
		vvi temp = sum(a, k - 1, mod);
		vvi x = mult(temp, a, mod);
		return add(x, a, mod);
	}
	vvi temp = sum(a, k / 2, mod);
	vvi powk_2 = pow(a, k / 2, mod);
	vvi y = mult(temp, powk_2, mod);
	return add(y, temp, mod);
}

//Функция countTours возвращает количество разных циклов в графе g,
//длины которых меньше чем k, взятое по модулю m.
int countTours(vector<string> &g, int k, int m)
{
	int i, j, n = g.size();
	vvi mas(n, vi(n, 0));
	long res;

	//Преобразуем матрицу смежности из массива строк g в двумерный целочисленный массив mas.
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (g[i][j] == 'Y') mas[i][j] = 1;
			else mas[i][j] = 0;
			res = 0;

			//В матрице temp вычислим сумму a + a^2 + a^3 + … + a^(k - 1). Все вычисления проводим по модулю m.
			vvi temp = sum(mas, k - 1, m);

			//В переменной res находим след матрицы temp.
			for (i = 0; i < n; i++) res = (res + temp[i][i]) % m;
			return res;
}

int main()
{
	scanf("%d %d %d\n", &n, &k, &m);
	g.clear();
	for (int i = 0; i < n; i++)
	{
		gets(line);
		g.push_back(line);
	}
	res = countTours(g, k, m);
	printf("%d\n", res);
	return 0;
}
