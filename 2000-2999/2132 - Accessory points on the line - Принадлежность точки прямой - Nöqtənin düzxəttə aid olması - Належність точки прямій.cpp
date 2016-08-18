#include <iostream>

using namespace std;

int main() {
	int a, b, c, x, y;
	scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
	printf(a*x + b*y + c ? "NO\n" : "YES\n");
	return 0;
}
