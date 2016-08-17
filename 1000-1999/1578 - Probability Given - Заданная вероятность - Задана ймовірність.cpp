#include <iostream>
#include <string.h>

using namespace std;

double p[21], prob[21], all;
int n, r, m[21];

//Функция generate генерирует последовательности длины n, состоящие из n – r нулей и r единиц.
//Каждой такой последовательности соответствует подмножество из r друзей. Для каждого подмножества
//друзей вычисляем вероятность их покупок и добавляем к all. Если в это подмножество входит i-ый друг,
//то вероятность прибавим и к prob[i].
void generate(int pos, int r)
{
	double p1;
	int i;
	if (pos + r > n || r < 0) return;
	if (!r && pos == n)
	{
		for (p1 = 1.0, i = 0; i < n; i++)
			if (m[i]) p1 *= p[i];
			else p1 *= (1 - p[i]);
			all += p1;
			for (i = 0; i < n; i++)
				if (m[i]) prob[i] += p1;
			return;
	}
	generate(pos + 1, r);
	m[pos] = 1;
	generate(pos + 1, r - 1);
	m[pos] = 0;
}

int main() {
	int i, cs = 1;
	while (scanf("%d %d", &n, &r), n + r)
	{
		for (all = i = 0; i < n; i++) scanf("%lf", &p[i]);
		memset(m, 0, sizeof m);
		memset(prob, 0, sizeof prob);
		generate(0, r); // pos, r
		printf("Case %d:\n", cs++);
		for (i = 0; i < n; i++) printf("%.6lf\n", prob[i] / all);
	}
	return 0;
}
