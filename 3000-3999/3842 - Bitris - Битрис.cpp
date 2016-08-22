#include <iostream>
#include <string.h>

using namespace std;

#define MAX 200001

int i, n, val, res, m[MAX], Fenwick[MAX];

int Summma0_i(int i)
{
	int z = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) z += Fenwick[i];
	return z;
}

int Summmai_j(int i, int j)
{
	return Summma0_i(j) - Summma0_i(i - 1);
}

void IncElement(int i, int delta)
{
	for (; i < MAX; i = i | (i + 1)) Fenwick[i] += delta;
}

int main() {
	scanf("%d", &n);
	memset(m, -1, sizeof m);
	res = 0;
	for (i = 1; i <= 2 * n; i++)
	{
		scanf("%d", &val);
		if (m[val] == -1)
		{
			m[val] = i;
			IncElement(i, 1);
		}
		else
		{
			IncElement(m[val], -1);
			res += Summmai_j(m[val], i);
		}
	}
	printf("%d\n", res);
	return 0;
}
