#include <iostream>
#include <string.h>

using namespace std;

int i, n, k, len;
char s[1001];

int Uinv(int i)
{
	if (i % 2) return (i + 1) / 2;
	return n / 2 + i / 2;
}

int Dinv(int i)
{
	if (i % 2) return n / 2 + (i + 1) / 2;
	return i / 2;
}

int main() {
	scanf("%d %d\n", &n, &k);
	gets(s);
	len = strlen(s);
	for (i = len - 1; i >= 0; i--)
	{
		if (s[i] == 'U') k = Uinv(k);
		else k = Dinv(k);
	}
	printf("%d\n", k);
	return 0;
}
