#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, x, uk = 0;
	cin >> n;
	vector<int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		m.push_back(x);
		if (x == 1) uk = i;
	}
	cout << 1 << " ";
	for (int i = uk + 1; i < n; i++) cout << m[i] << " ";
	for (int i = 0; i < uk; i++) cout << m[i] << " ";
	return 0;
}
