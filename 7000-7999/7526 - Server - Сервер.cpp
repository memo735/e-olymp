#include <iostream>

using namespace std;

int main()
{
	int n, m, k = 0, s = 0;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		s += arr[i];
		if (s <= m) k++;
	}
	cout << k;
	return 0;
}
