#include <stdio.h>

int x, i, n, a, b, c;
long Res = 0;

class Deque
{
public:
	int *value, *mn, Bvalue, Evalue, Bmn, Emn;

	Deque(int n = 1000010)
	{
		value = new int[n];
		mn = new int[n];
		Bvalue = Evalue = Bmn = Emn = 0;
	}

	~Deque()
	{
		delete[] value;
		delete[] mn;
	}

	void pop()
	{
		if (Bvalue != Evalue)
		{
			if (value[Bvalue] == mn[Bmn]) Bmn++;
			Bvalue++;
		}
	}

	int getMin() const
	{
		return Bmn != Emn ? mn[Bmn] : 0;
	}

	void push(int x)
	{
		value[Evalue++] = x;
		while (Bmn != Emn && x < mn[Emn - 1]) Emn--;
		mn[Emn++] = x;
	}
};

int main()
{
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &x);
	Deque d(n);
	for (i = 1; i <= n; i++)
	{
		x = (1L * a * x * x + 1L * b * x + c) / 100 % 1000000L;
		if (x % 5 < 2) d.pop(); // удалить из очереди
		else d.push(x); // добавить в очередь значение x
		Res += d.getMin();
	}
	printf("%ld\n", Res);
	return 0;
}
