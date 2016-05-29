#include <stdio.h>

long a, b, s, d, x, y;

void exgcd(long a, long b, long& d, long& x, long& y) {
	if (!b) { d = a; x = 1; y = 0; }
	else {
		exgcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }

void work() {
	if (a == 0) {
		if (b == 0) printf("%s\n", s ? "NO" : "YES");
		else printf("%s\n", s % b ? "NO" : "YES");
		return;
	}
	if (b == 0) { printf("%s\n", s % a ? "NO" : "YES"); return; }
	exgcd(a, b, d, x, y);
	if (s % d) { puts("NO"); return; }
	a /= d; b /= d; s /= d;
	x *= s % b; x %= b;
	while (x < 0) x += b;
	y = (s - a * x) / b;
	while (y >= 0) {
		if (gcd(x, y) == 1) { puts("YES"); return; }
		x += b; y -= a;
	}
	puts("NO");
}

int main() {
	while (~scanf("%ld %ld %ld", &a, &b, &s))  work();
	return 0;
}
