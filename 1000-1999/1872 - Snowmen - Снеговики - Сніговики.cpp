#include <iostream>

struct Pair
{
	int Number, Weight;
} Sman[200001];

int i, n, t, m;
long sum;

int main()
{
	scanf("%d", &n); sum = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &t, &m);
		if (m > 0)
		{
			Sman[i].Number = t;
			Sman[i].Weight = Sman[t].Weight + m;
		}
		else Sman[i] = Sman[Sman[t].Number];
		sum += Sman[i].Weight;
	}
	printf("%ld\n", sum);
	return 0;
}
