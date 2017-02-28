#include <iostream>

using namespace std;

int main() {
	int a, b, n, cnt = 1;
	scanf("%d %d %d", &a, &b, &n);
	while (a * b * cnt % n > 0) cnt++;
	printf("%d\n", cnt);
	return 0;
}
