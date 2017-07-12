#include <iostream>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", n / 2 + m / 2);
	for (int x = 2; x <= n; x += 2) printf("%d %d %d %d\n", x, 1, x, m);
	for (int y = 2; y <= m; y += 2) printf("%d %d %d %d\n", 1, y, n, y);
	return 0;
}
