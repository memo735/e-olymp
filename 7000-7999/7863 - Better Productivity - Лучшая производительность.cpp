#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct Interval :pair<int, int> {
	int &l() { return first; }
	int &r() { return second; }
	int size() { return r() - l(); }
};

Interval v[200];
vector<int> spare;

int main() {
	int n, p; cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> v[i].l() >> v[i].r();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].l() <= v[j].l() && v[i].r() > v[j].r() || v[i].l() < v[j].l() && v[i].r() >= v[j].r()) {
				spare.push_back(v[i].size());
				swap(v[i--], v[--n]); break;
			}
		}
	}
	sort(v, v + n);
	sort(spare.rbegin(), spare.rend());
	for (int i = 1; i < spare.size(); i++) spare[i] += spare[i - 1];
	int dp[201][201];
	memset(dp, 0x80, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < spare.size(); i++) dp[0][i + 1] = spare[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			if (dp[i][j] < 0) continue;
			for (int k = i; k < n && v[k].l() < v[i].r(); k++)
				dp[k + 1][j + 1] = max(dp[k + 1][j + 1], dp[i][j] + v[i].r() - v[k].l());
		}
	}
	cout << dp[n][p] << endl;
	return 0;
}
