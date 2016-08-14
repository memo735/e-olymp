#include <iostream>

int n, r1, r2, cnt;
char c;
double res, PI = 3.1415926535897932384626433832795;

int main() {
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &r1);
		scanf("%c", &c); cnt = 1;
		if (c == ' ') scanf("%d\n", &r2), cnt = 2;
		if (cnt == 2) res = 2 * PI*r1*r2; else res = PI * r1 * r1 / 8;
		printf("%.4lf\n", res);
	}
	return 0;
}
