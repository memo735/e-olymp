#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100001;

int main() {
	int n, h[N];
	vector <int> ev[N];
	long m, ans[N], sum[N];
	scanf("%d %ld", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", h + i);
	int low = 0;
	for (int i = 0; i < n; i++) low = max(low, h[i]);
	int high = int(1.01e9);
	while (low < high) {
		int mid = (low + high + 1) >> 1;
		for (int i = 0; i < n; i++) ans[i] = 0;
		for (int rot = 0; rot < 2; rot++) {
			sum[0] = h[0];
			for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + h[i];
			for (int i = 0; i < n; i++) ev[i].clear();
			for (int i = 0; i < n; i++) {
				int j = i + mid - h[i];
				if (j < n) ev[j].push_back(i);
			}
			int mx = -1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < int(ev[i].size()); j++) mx = max(mx, ev[i][j]);
				if (mx >= 0) {
					int from = mid - 1, to = mid - (i - mx) + 1;
					ans[i] += (to + from) * 1L * (from - to + 1) / 2;
					ans[i] -= (sum[i - 1] - sum[mx]);
				}
				else ans[i] += 2e18;
			}
			for (int i = 0; i < n - i - 1; i++) {
				swap(h[i], h[n - i - 1]);
				swap(ans[i], ans[n - i - 1]);
			}
		}
		bool found = false;
		for (int i = 0; i < n; i++) {
			ans[i] += mid - h[i];
			if (ans[i] <= m) {
				found = true;
				break;
			}
		}
		found ? low = mid : high = mid - 1;
	}
	printf("%d\n", low);
	return 0;
}
