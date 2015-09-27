#include <iostream>

using namespace std;

long long n;

bool simp(long long param)
{
	for (int j = 2; j*j <= param; j++) if (param % j == 0) return false;
	return true;
}

int main()
{
	cin >> n;
	for (int i = 2; i*i < n; i++)
		if (n % i == 0)
			if (simp(i) && simp(n / i))
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
}
