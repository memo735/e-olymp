#include <iostream>
#include <string.h>

using namespace std;

const int mod = 2007;

#define K 11
int p[K][K], q[K][K];

void mul(int a[][K], int b[][K], int s)
{
	int c[K][K];
	memset(c, 0, sizeof c);
	for (int i = 0; i <= s; ++i)
		for (int j = 0; j <= s; ++j)
			for (int k = 0; k <= s; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	memcpy(a, c, sizeof c);
}

void pt(int a[][K], int s)
{
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j) cout << a[i][j] << ' ';
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	int n, k; cin >> n >> k;
	q[0][0] = 1;
	for (int i = 1; i <= k; ++i) q[i][i] = 1, p[i][i] = i, p[i][i - 1] = 1;
	for (int i = 1; i <= n; i <<= 1)
	{
		if (i & n) mul(q, p, k);
		mul(p, p, k);
	}
	cout << q[k][0] << endl;
	return 0;
}
