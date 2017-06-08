#include <stdio.h>

int n, a, b, c, m;

int main() {
	scanf("%d", &n);
	a = n - n / 100 * 100;
	b = n / 100 * 10 + n % 10;
	c = (n - n % 10) / 10;
	m = c;
	if (b <= c && b / 10 >= 1) m = b;
	if (a < b && a / 10 >= 1) m = a;
	printf("%d", m);
	return 0;
}
