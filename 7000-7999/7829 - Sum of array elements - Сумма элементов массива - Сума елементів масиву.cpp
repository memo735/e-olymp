#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	double cem = 0.0, a[101];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		cem += a[i];
	}
	cout << cem;
	return 0;
}
