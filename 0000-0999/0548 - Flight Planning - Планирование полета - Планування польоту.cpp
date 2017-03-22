#include <string.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
const int inf = 1 << 20;

vector<int> adj[10000];
int kill1, kill2, succ[10000];

int depth(int v, int par = -1) {
	int r = 0;
	succ[v] = v;
	for (vi::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
		if (*it != par && (v != kill1 || *it != kill2) && (*it != kill1 || v != kill2)) {
			int d = depth(*it, v) + 1;
			if (d > r) {
				r = d;
				succ[v] = *it;
			}
		}
	return r;
}

int follow(int v, int steps) { for (int i = 0; i < steps; ++i) v = succ[v]; return v; }

int main() {
	int n;
	scanf("%d", &n);
	assert(4 <= n && n <= 2500);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		assert(1 <= a && a <= n);
		assert(1 <= b && b != a && a <= n);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// check that it's really a tree
	kill1 = kill2 = -1;
	memset(succ, -1, sizeof succ);
	depth(1);
	for (int i = 1; i <= n; ++i) assert(succ[i] != -1);
	int v = follow(1, n);
	int olddiam = depth(v);
	int best = inf, bi = 0, bj = 0, ri = 0, rj = 0;
	for (int i = 1; i <= n; ++i)
		for (vi::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
			if (*it > i) {
				kill1 = i;
				kill2 = *it;
				int d1 = depth(i), d2 = depth(*it);
				int v1 = follow(i, d1), v2 = follow(*it, d2);
				assert(succ[v2] == v2);
				int diam1 = depth(v1), diam2 = depth(v2);
				int res = max(max(diam1, diam2), (diam1 + 1) / 2 + (diam2 + 1) / 2 + 1);
				if (res < best) best = res, bi = i, bj = *it, ri = follow(v1, diam1 / 2), rj = follow(v2, diam2 / 2);
			}
		}
	assert(best < olddiam);
	printf("%d\n%d %d\n%d %d\n", best, bi, bj, ri, rj);
	return 0;
}
