#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	string a, b;
	for (int i = 0; i < m / 9; i++) a += 9 + 48;
	if (m % 9) a += m % 9 + 48;
	for (int i = 0; i < n - m / 9 - (m % 9 != 0); i++) a += 48;
	for (int i = a.length() - 1; i >= 0; i--) b += a[i];
	if (b[0] == 48)
		for (int i = 1; i < b.length(); i++)
			if (b[i] != 48)
			{
				b[0] = 49;
				b[i]--;
				break;
			}
	cout << b << " " << a << endl;
}
