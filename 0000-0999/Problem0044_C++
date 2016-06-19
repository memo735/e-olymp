#include <iostream>
#include <algorithm>

using namespace std;

int dn[5000];

int rec(int index)
{
	if (dn[index] != -1) return dn[index];
	int ans = 1 + rec(index - 1);
	for (int i = 2; i < index / 2; i++) ans = min(ans, rec(i) + rec(index - i));
	for (int i = 2; i <= sqrt(index); i++) if (index % i == 0) ans = min(ans, rec(i) + rec(index / i));
	return dn[index] = ans;
}

int main()
{
	int n;  cin >> n;
	for (int i = 0; i <= n; i++) dn[i] = -1;
	dn[0] = dn[1] = 1;
	cout << rec(n) << endl;
}
