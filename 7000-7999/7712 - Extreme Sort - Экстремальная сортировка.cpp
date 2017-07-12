#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a[1 << 10];
	for (int i = 0; i <= a[0]; i++) cin >> a[i];
	cout << (prev_permutation(a + 1, a + 1 + a[0]) ? "no" : "yes") << endl;
}
