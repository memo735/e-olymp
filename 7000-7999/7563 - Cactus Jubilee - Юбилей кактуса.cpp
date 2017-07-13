#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g, cg;
int n, m, timer;

vector<pair<int, int>> st;
vector<int> tin, tup;

void dfs0(int v, int p) {
	tin[v] = tup[v] = timer++;
	for (int u : g[v]) {
		if (u == p) continue;
		if (tin[u] > tin[v]) continue;
		st.push_back(make_pair(v, u));
		if (tin[u] != -1) {
			tup[v] = min(tup[v], tin[u]);
			continue;
		}
		dfs0(u, v);
		tup[v] = min(tup[v], tup[u]);
		if (tup[u] >= tin[v]) {
			vector<int> cycle;
			cycle.push_back(v);
			while (true) {
				auto x = st.back();
				st.pop_back();
				if (x == make_pair(v, u)) break;
				cycle.push_back(x.first);
			}
			if (cycle.size() == 1) cycle.push_back(u);
			if (cycle.size() == 2) {
				cg[cycle[0]].push_back(cycle[1]);
				cg[cycle[1]].push_back(cycle[0]);
			}
			else {
				int cid = cg.size();
				cg.push_back(cycle);
				for (int t : cycle) cg[t].push_back(cid);
			}
		}
	}
}

vector<int> tid, tsz;
long ans;

void dfs1(int v, int t) {
	tsz[t]++;
	tid[v] = t;
	for (int u : cg[v]) {
		if (u < n && tid[u] == -1) dfs1(u, t);
	}
}

int dfs2(int v, int p) {
	int cur = v < n;
	for (int u : cg[v]) {
		if (u == p) continue;
		int temp = dfs2(u, v);
		cur += temp;
		if (v < n && u < n) ans += temp * 1L * (n - temp) - 1;
	}
	return cur;
}

long calc(int size) {
	return size * 1L * (size - 1) / 2 - (size - 1);
}

int main() {
	scanf("%d%d", &n, &m);
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int k, prev;
		scanf("%d", &k);
		scanf("%d", &prev);
		--prev;
		for (int j = 1; j < k; j++) {
			int next;
			scanf("%d", &next);
			--next;
			g[prev].push_back(next);
			g[next].push_back(prev);
			prev = next;
		}
	}
	tin.resize(n, -1);
	tup.resize(n, -1);
	cg.resize(n);
	dfs0(0, -1);
	tid.resize(n, -1);
	for (int i = 0; i < n; i++)
		if (tid[i] == -1) {
			tsz.push_back(0);
			dfs1(i, tsz.size() - 1);
		}
	dfs2(0, -1);
	long sum = 0;
	for (int i = 0; i < tsz.size(); i++) sum += calc(tsz[i]);
	for (int i = n; i < cg.size(); i++) {
		long temp = sum;
		int tot = 0;
		for (int v : cg[i]) {
			temp -= calc(tsz[tid[v]]);
			tot += tsz[tid[v]];
		}
		temp += calc(tot);
		ans += (temp - 1) * cg[i].size();
	}
	printf("%ld\n", ans);
	return 0;
}
