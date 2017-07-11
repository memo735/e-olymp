#include <iostream>

using namespace std;

int main() {
	int n, max = -1001, cem = 0, a[101]; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > max) max = a[i];
	}
	for (int i = 0; i < n; ++i) if (a[i] != max) cem += a[i];
	cout << cem;
	return 0;
}
