#include <iostream>

using namespace std;

int main() {
	int n, max = -1001, say = 0, a[101]; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > max) max = a[i];
	}
	for (int i = 0; i < n; ++i) if (a[i] == max) say++;
	cout << say;
	return 0;
}
