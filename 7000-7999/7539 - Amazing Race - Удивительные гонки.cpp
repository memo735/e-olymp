#include <iostream>
#include <cassert>
#include <algorithm>

#define MAXN 20

using namespace std;

int n, T, p[MAXN], t[MAXN], d[MAXN];
int dist[MAXN + 2][MAXN + 2];
int dp[1 << MAXN][MAXN + 2];

bool smaller(int a, int b) {
	while (a && b) {
		if ((a & 1) > (b & 1)) return true;
		if ((a & 1) < (b & 1)) return false;
		a >>= 1;
		b >>= 1;
	}
	assert(false);
}

int main() {
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> t[i] >> d[i];
		if (d[i] == -1) d[i] = T + 1;
	}
	for (int i = 0; i < n + 2; ++i)
		for (int j = 0; j < n + 2; ++j) cin >> dist[i][j];

	for (int i = 0; i < 1 << n; ++i)
		for (int j = 0; j < n + 2; ++j) dp[i][j] = T + 1;

	dp[0][n] = 0;
	for (int i = 0; i < 1 << n; ++i) {
		for (int j = i ? 0 : n; j < (i ? n : n + 1); ++j) {
			if (i && !(i & 1 << j)) continue;
			if (dp[i][j] > T) continue;
			for (int k = 0; k < n; ++k) {
				if (i & 1 << k) continue;
				int done = dp[i][j] + dist[j][k] + t[k];
				if (done > d[k]) continue;
				dp[i | 1 << k][k] = min(dp[i | 1 << k][k], done);
			}
			dp[i][n + 1] = min(dp[i][n + 1], dp[i][j] + dist[j][n + 1]);
		}
	}
	int mx = -1, id = -1, hw = 0;
	for (int i = 0; i < 1 << n; ++i) {
		if (dp[i][n + 1] <= T) {
			int val = 0, ham = 0;
			for (int j = 0; j < n; ++j)
				if (i & 1 << j) { val += p[j]; ++ham; }
			if (val > mx || val == mx && smaller(i, id)) id = i, mx = val, hw = ham;
		}
	}
	if (mx > 0) {
		cout << mx << endl;
		for (int j = 0; j < n; ++j)
			if (id & 1 << j) {
				cout << j + 1;
				--hw ? cout << ' ' : cout << endl;
			}
	}
	else cout << 0 << endl << endl;
	return 0;
}
