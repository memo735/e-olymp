#include <iostream>

using namespace std;

int d[10001];

int dp(int param)
{
	if (param == 1) return 0;
	if (d[param] != -1) return d[param];
	int med = 1;
	while (med * 2 < param) if (!dp(param - med++)) return d[param] = 1;
	return d[param] = 0;
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i <= n; i++) d[i] = -1;
	int TMP = 1;
	while (TMP * 2 < n)
	{
		if (!dp(n - TMP)) { cout << TMP << endl; return 0; }
		TMP++;
	}
	cout << 0 << endl;
}
