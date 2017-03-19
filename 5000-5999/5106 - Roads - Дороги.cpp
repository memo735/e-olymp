#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a; cin >> a;
	vector<int> A, B;
	A = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	B = A;
	while (--a) {
		for (int i = 0; i < 10; i++) {
			if (!i) {
				B[i] += A[i + 1];
				continue;
			}
			if (i == 9) {
				B[i] += A[i - 1];
				continue;
			}
			B[i] += A[i - 1] + A[i + 1];
		}
		A = B;
	}
	long ans = 0;
	for (int i = 0; i < 10; i++) ans += A[i];
	cout << ans;
	return 0;
}
