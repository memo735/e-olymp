#include <iostream>

using namespace std;

long i, j, l, r, x, Fenwick[100001];
int n, k;
char command;

// Fenwick[0] + Fenwick[1] + ... + Fenwick[i]
long Summma0_i(long i)
{
	long res = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) res += Fenwick[i];
	return res;
}

// Fenwick[i] = Fenwick[i] + delta
void IncElement(long i, long delta)
{
	for (; i <= n; i = i | i + 1) Fenwick[i] += delta;
}

int main()
{
	scanf("%d %d\n", &n, &k);
	for (j = 0; j < k; j++)
	{
		scanf("%c", &command);
		if (command == 'A')
		{
			scanf("%ld %ld\n", &i, &x);
			x = x - Summma0_i(i) + Summma0_i(i - 1);
			IncElement(i, x);
		}
		else
		{
			scanf("%ld %ld\n", &l, &r);
			printf("%ld\n", Summma0_i(r) - Summma0_i(l - 1));
		}
	}
	return 0;
}
