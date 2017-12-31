#include <iostream>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	cout << (n + k - 1) / k + (m + k - 1) / k;
	return 0;
}
