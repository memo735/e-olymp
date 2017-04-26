#include <iostream>

using namespace std;

int main() {
	int min = 1e9, max = -1e9, n, a[101];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] < min) min = a[i];
		if (a[i] > max) max = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == min) cout << max;
		else if (a[i] == max) cout << min;
		else cout << a[i];
		if (i < n - 1) cout << " ";
	}
	return 0;
}
