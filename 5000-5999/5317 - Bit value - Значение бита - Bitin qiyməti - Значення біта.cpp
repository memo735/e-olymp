#include <iostream>

using namespace std;

int main() {
	int a, k;
	cin >> a >> k;
	printf("%d\n", (a & 1 << k) > 0);
	return 0;
}
