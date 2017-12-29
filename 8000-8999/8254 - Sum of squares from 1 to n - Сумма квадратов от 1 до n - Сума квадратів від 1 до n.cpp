#include <stdio.h>

long i, n, s;

int main()
{
	scanf("%ld", &n);
	s = n * (n + 1) * (2 * n + 1) / 6;
	printf("%ld\n", s);
	return 0;
}
