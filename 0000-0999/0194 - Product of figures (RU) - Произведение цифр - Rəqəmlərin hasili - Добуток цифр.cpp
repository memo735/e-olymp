#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, tmp, A = 0, B = 0; cin >> n;
	tmp = n;
	string a, b;
	for (int i = 2; i < 10; i++)
		while (tmp % i == 0)
		{
			a += i + 48;
			tmp /= i;
		}
	tmp = n;
	for (int i = 9; i > 1; i--)
		while (tmp % i == 0)
		{
			b += i + 48;
			tmp /= i;
		}
	if (tmp != 1) cout << -1 << " " << -1 << endl;
	else
	{
		for (int i = a.length() - 1; i >= 0; i--) A = A * 10 + a[i] - 48;
		for (int i = b.length() - 1; i >= 0; i--) B = B * 10 + b[i] - 48;
		cout << min(A, B) << " " << max(A, B) << endl;
	}
}
