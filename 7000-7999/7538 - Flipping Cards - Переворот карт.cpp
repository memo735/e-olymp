#include <iostream>

using namespace std;

int uf[100001];
bool fz[100001];

void init(int n) {
	for (int i = 0; i < 2 * n; ++i) {
		uf[i] = i;
		fz[i] = false;
	}
}

int find(int i)
{
	if (uf[i] == i) return i;
	return uf[i] = find(uf[i]);
}

bool merge(int i, int j) {
	i = find(i), j = find(j);
	if (fz[i] && fz[j]) return false;
	fz[j] |= fz[i] || i == j;
	uf[i] = j;
	return true;
}

bool solve() {
	int n; cin >> n;
	init(n);
	bool ok = true;
	while (n--) {
		int u, v; cin >> u >> v;
		ok &= merge(u - 1, v - 1);
	}
	return ok;
}

int main() {
	int t; cin >> t;
	while (t--) cout << (solve() ? "possible" : "impossible") << endl;
	return 0;
}
