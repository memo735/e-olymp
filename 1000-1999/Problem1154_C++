#include <iostream>

using namespace std;

int n, m;

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
	while (cin)
	{
		cin >> n >> m;
		if (cin)
		{
			if (gcd(n, m) == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
