#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int main()
{
	int n, m; cin >> n >> m;
	if (n == 1 || m == 1) cout << 1 << endl;
	else cout << gcd(n, m) << endl;
}
