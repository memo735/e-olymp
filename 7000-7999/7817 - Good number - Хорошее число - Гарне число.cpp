#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	long res = 1;
	for (int i = 0; i < n; i++) res *= 5;
	printf("%ld\n", res);
	return 0;
}
