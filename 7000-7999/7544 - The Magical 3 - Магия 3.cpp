#include <iostream>

using namespace std;

long prime(long n) {
	for (long i = 2; i*i <= n; ++i) if (n%i == 0) return i;
	return n;
}

long solve(long n) {
	for (long m = 4; m <= 10; ++m) if (n%m == 3) return m;
	if (n <= 6) return -1;
	long p = prime(n - 3);
	return p > 3 ? p : prime((n - 3) / p);
}

int main() {
	int n;
	while (cin >> n && n) {
		int s = solve(n);
		(s == -1 ? cout << "No such base" : cout << s) << endl;
	}
	return 0;
}
