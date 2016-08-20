#include <iostream>

using namespace std;

int main()
{
	int n, k, i = -1;
	cin >> n; n++;
	do {
		i++;
		k = 1 + i * (i + 1) / 2;
	} while (k < n);
	cout << i;
	return 0;
}
