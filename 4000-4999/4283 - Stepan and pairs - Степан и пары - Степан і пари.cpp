#include <iostream>

using namespace std;

int main() {
	int i, n, s = 0;
	cin >> n;
	for (i = 1; i <= n; i++) s += n / i;
	printf("%d\n", s);
	return 0;
}
