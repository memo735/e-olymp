#include <iostream>

using namespace std;

void gcdext(int a, int b, int *d, int *x, int *y)
{
	int s;
	if (b == 0)
	{
		*d = a; *x = 1; *y = 0;
		return;
	}
	gcdext(b, a % b, d, x, y);
	s = *y;
	*y = *x - (a / b) * (*y);
	*x = s;
}

int main() {
	int a, b, d, x, y;
	while (scanf("%d %d", &a, &b) == 2)
	{
		gcdext(a, b, &d, &x, &y);
		printf("%d %d %d\n", x, y, d);
	}
	return 0;
}
