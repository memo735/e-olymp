#include <iostream>

using namespace std;

int i, j, N, x, ans, a[100], b[100];

int gcd(int a, int b) {
	return b > 0 ? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
	return 1LL * a*b / gcd(a, b);
}

int main() {
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[i] = 1;
	}
	ans = 1;
	for (i = 0; i < N; i++) {
		x = 0; j = i;
		while (b[j]) {
			b[j] = 0;
			j = a[j] - 1;
			x++;
		}
		if (x > 0) ans = lcm(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}
