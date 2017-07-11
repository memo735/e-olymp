#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair <int, int> pii;

struct RangeTree {
	int n, kk;
	vector <int> sum;
	RangeTree(int n) : n(n) {
		kk = 1;
		while (kk < n) kk *= 2;
		sum.resize(2 * kk + 10);
		for (int i = 0; i < n; ++i) sum[kk + i] = 1;
		for (int i = kk - 1; i >= 1; --i) sum[i] = sum[2 * i] + sum[2 * i + 1];
	}
	int useLeftest() {
		if (sum[1] == 0) return n;
		int t = 1;
		while (t < kk) {
			assert(sum[t] > 0);
			t *= 2;
			if (sum[t] == 0) t++;
		}
		assert(sum[t] > 0);
		increment(t - kk, -1);
		return t - kk;
	}
	void increment(int pos, int delta) {
		int t = pos + kk;
		sum[t] += delta;
		while (t > 1) {
			t /= 2;
			sum[t] = sum[2 * t] + sum[2 * t + 1];
		}
	}
};

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector <pair<int, int>> events;
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		events.push_back(pair<int, int>(a, i));
		events.push_back(pair<int, int>(b, ~i));
	}
	sort(events.begin(), events.end());
	vector <int> start(k);
	vector <int> pos(k, -2);
	vector <int> res(m, 0);
	int sits = m - 1;
	RangeTree tree(m);
	for (const auto & ev : events) {
		int curT = ev.first, num = ev.second;
		if (num >= 0) {
			assert(0 <= num && num < k);
			start[num] = curT;
			if (sits > 0) {
				--sits;
				pos[num] = -1;
			}
			else pos[num] = tree.useLeftest();
		}
		else {
			num = ~num;
			assert(0 <= num && num < k);
			assert(-1 <= pos[num] && pos[num] <= m);
			if (pos[num] == -1) ++sits;
			else if (pos[num] < m) {
				tree.increment(pos[num], 1);
				res[pos[num]] += curT - start[num];
			}
		}
	}
	int resPos = -1, resT = 2 * n;
	for (int i = 0; i < m; ++i) {
		if (res[i] < resT) {
			resPos = i;
			resT = res[i];
		}
	}
	printf("%d %d\n", resT, resPos + 1);
	return 0;
}
