#include <iostream>

using namespace std;

const long MOD = 1000000;

class Matrix
{
public:
	long a, b, c, d;
	Matrix(long a = 1, long b = 0, long c = 0, long d = 1)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	//Перегрузим оператор умножения матриц.
	Matrix operator* (const Matrix &x) const
	{
		Matrix res;
		res.a = (a * x.a + b * x.c) % MOD;
		res.b = (a * x.b + b * x.d) % MOD;
		res.c = (c * x.a + d * x.c) % MOD;
		res.d = (c * x.b + d * x.d) % MOD;
		return res;
	}

	//Перегрузим оператор возведения матрицы в степень n.
	Matrix operator^ (int n) const
	{
		Matrix res, x(*this);
		while (n > 0)
		{
			if (n & 1) res = res * x;
			n >>= 1;
			x = x * x;
		}
		return res;
	}
};

//Возводим матрицу res в степень n.
long Solve(long n)
{
	Matrix res(1, 1, 2, 3);
	res = res^n;
	return res.a;
}

//Если значение n не делится на 3, то ответ 0. Иначе делим n на 3 и возводим матрицу res в степень n + 1.
int main() {
	int n, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		if (n % 3)
		{
			printf("0\n");
			continue;
		}
		n /= 3;
		long res = Solve(n + 1);
		printf("%ld\n", res);
	}
	return 0;
}
