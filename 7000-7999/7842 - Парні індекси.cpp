#include <iostream>

using namespace std;

int main() {
	int n, a[101]; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (i % 2 == 0) cout << a[i] << " ";
	}
	return 0;
}
