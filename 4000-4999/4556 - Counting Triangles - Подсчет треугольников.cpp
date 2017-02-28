#include <iostream>

long T(long n)
{
	return n * (n + 1) / 2;
}

int main()
{
	int tests, i;
	long n, s[1000001][2];
	s[1][0] = 1; s[2][0] = 3;
	s[1][1] = 0; s[2][1] = 1;
	for (i = 2; i < 1000001; i++)
	{
		s[i][0] = s[i - 1][0] + T(i);
		s[i][1] = s[i - 2][1] + T(i - 1);
	}
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%ld", &n);
		printf("%ld\n", s[n][0] + s[n][1]);
	}
	return 0;
}
