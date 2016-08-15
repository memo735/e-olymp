#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main() {
	int n; scanf("%d", &n);
	for (int test = 0; test < n; test++)
	{
		int dim, a[11], b[11], d[11];
		scanf("%d", &dim);
		for (int i = 0; i < dim; i++) scanf("%d", &a[i]);
		for (int i = 0; i < dim; i++) scanf("%d", &b[i]);

		//Вычисляем массив d = (| p1 – q1 | , | p2 – q2 | , …, | pn – qn | ) = (d1, d2, …, dn).
		for (int i = 0; i < dim; i++)
			if (a[i] > b[i]) d[i] = a[i] - b[i];
			else d[i] = b[i] - a[i];
			int res = 0;

			//Перебираем все подмножества множества {d1, d2, …, dn}. Каждое подмножество генерируется
			//по числу i(1 £ i £ 2^dim – 1), выбирая из его двоичного представления позиции, на которых стоят единицы.
			for (int i = 1; i < 1 << dim; i++)
			{
				int j, ptr, temp, cnt;
				ptr = temp = cnt = 0; j = i;
				while (j > 0)
				{
					if (j % 2)
					{
						temp = gcd(temp, d[ptr]);
						cnt++;
					}
					ptr++; j /= 2;
				}
				//Если подмножество состоит из четного количества элементов, то НОД его элементов
				//вычитается их общего результата.Если из нечетного – то прибавляется.
				if (cnt % 2) res += temp;
				else res -= temp;
			}
			printf("Case %d: %d\n", test + 1, res);
	}
	return 0;
}
