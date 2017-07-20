#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1000000007;

void madd(int &a, int b) {
	if ((a += b) >= MOD) a -= MOD;
}

int t;

vector<int> process(const vector<int>& start, int q, int x)
{
	int maxSleep = min((q + t) / (t + 1), q - x);
	vector<vector<int>> dyn, ndyn;
	dyn.resize(t + 1);
	ndyn.resize(t + 1);
	for (int i = 0; i <= t; i++) {
		dyn[i].resize(maxSleep + 1);
		ndyn[i].resize(maxSleep + 1);
		fill(dyn[i].begin(), dyn[i].end(), 0);
		dyn[i][0] = start[i];
	}
	for (int repid = 0; repid < q; repid++) {
		for (int i = 0; i < ndyn.size(); i++)
			fill(ndyn[i].begin(), ndyn[i].end(), 0);

		for (int i = 0; i < t + 1; i++) {
			for (int j = 0; j < maxSleep + 1; j++) {
				int cv = dyn[i][j];
				if (!cv) continue;
				madd(ndyn[max(0, i - 1)][j], cv);
				if (!i && j < maxSleep) madd(ndyn[t][j + 1], cv);
			}
		}
		dyn.swap(ndyn);
	}
	vector<int> res(t + 1);
	for (int i = 0; i < t + 1; i++)
		for (int j = 0; j < maxSleep + 1; j++) madd(res[i], dyn[i][j]);
	return res;
}

int main() {
	int n;
	while (scanf("%d%d", &n, &t) == 2) {
		vector<int> curst(t + 1, 0);
		curst[0] = 1;
		for (int id = 0; id < n; id++) {
			int q, x;
			scanf("%d%d", &q, &x);
			curst = process(curst, q, x);
		}
		int ans = 0;
		for (int i = 0; i < curst.size(); i++) madd(ans, curst[i]);
		printf("%d\n", ans);
	}
	return 0;
}
