#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 100001;

int sa[maxn], height[maxn], _rank[maxn], t1[maxn], t2[maxn], c[maxn];
string s;

void get_sa(const int &n, int m)
{
	int i, k, *x = t1, *y = t2;
	for (i = 0; i < m; i++) c[i] = 0;
	for (i = 0; i < n; i++) ++c[x[i] = s[i]];
	for (i = 1; i < m; i++) c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (k = 1; k <= n; k <<= 1) {
		int p = 0;
		for (i = n - k; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
		for (i = 0; i < m; i++) c[i] = 0;
		for (i = 0; i < n; i++) ++c[x[y[i]]];
		for (i = 1; i < m; i++) c[i] += c[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y), p = 1, x[sa[0]] = 0;
		for (i = 1; i < n; i++)
			x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]) ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
	k = 0;
	for (i = 0; i < n; i++) _rank[sa[i]] = i;
	for (i = 0; i < n; i++) {
		if (k) --k; if (!_rank[i]) continue;
		int j = sa[_rank[i] - 1];
		while (s[i + k] == s[j + k]) k++;
		height[_rank[i]] = k;
	}
}

void print(const int &n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = sa[i]; j < n; j++) cout << s[j];
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int T, o; cin >> T;
	while (T--) {
		cin >> s;
		int sz = s.size();
		int n = sz;
		get_sa(n + 1, 256);
		int ans = o = 0;
		for (int i = 2; i <= n; i++) {
			ans += max(0, height[i] - o); o = height[i];
			//last line can be changed to "ans += max(0, height[i] - height[i-1]);"
		}
		cout << ans << "\n";
	}
	return 0;
}
