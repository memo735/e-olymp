#include <stdio.h>

int n, i, val;

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &val);
		if (val % 2 != 0) printf("%d ", val);
	}
	return 0;
}
