#include <iostream>

using namespace std;

int main() {
	int n, a[101]; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i % 2 == 1) swap(a[i], a[i - 1]);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
		if (i < n - 1) cout << " ";
	}
	return 0;
}
