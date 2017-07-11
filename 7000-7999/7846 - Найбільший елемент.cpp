#include <iostream>

using namespace std;

int main() {
	int n, max = -1001, index = 0, a[101]; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > max)
		{
			max = a[i];
			index = i + 1;
		}
	}
	cout << max << " " << index;
	return 0;
}
