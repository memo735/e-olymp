#include <iostream>

using namespace std;

int main() {
	int n, max = -1001, a[101]; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > max) max = a[i];
	}
	cout << max;
	return 0;
}
