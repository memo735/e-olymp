#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, a[101];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	cout << a[n - 1] + a[n - 2];
	return 0;
}
