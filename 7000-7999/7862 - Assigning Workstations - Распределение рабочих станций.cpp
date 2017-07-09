#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> ev(2 * n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		ev[2 * i] = pair<int, int>(a, 1);
		ev[2 * i + 1] = pair<int, int>(a + b, -1);
	}
	sort(ev.begin(), ev.end());
	priority_queue<int> q;
	int walks = 0;
	for (auto e : ev) {
		if (e.second < 0) q.push(-e.first - m);
		else {
			while (!q.empty() && -q.top() < e.first) q.pop();
			if (!q.empty()) q.pop(), ++walks;
		}
	}
	printf("%d\n", walks);
	return 0;
}
