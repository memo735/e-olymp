#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector <int> solve(int k, const vector <int> & a) {
	vector <int> res(a.size() + 1, 0);
	for (int i = 0, j = -1; i < int(a.size()); ++i) {
		while (j < i && a[j + 1] + k <= a[i]) ++j;
		res[i + 1] = res[j + 1] + min(k, a[i]);
	}
	return move(res);
}

int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	vector <int> a(m);
	for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	vector <int> pref = solve(k, a);
	reverse(a.begin(), a.end());
	for (int i = 0; i < m; ++i) a[i] = n - a[i] + 1;
	vector <int> suff = solve(k, a);
	int res = n;
	for (int i = 0; i <= m; ++i) {
		int cur = pref[i] + suff[m - i];
		res = min(res, cur);
	}
	printf("%d\n", n - res);
	return 0;
}
