#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100001;

vector<int> g[N];
int from[N], to[N], qx[N], qy[N], pos[N], que[N], res[N], d_fst[N], d_snd[N];

void bfs(vector <int> &v, vector <int> &ee, int start, int *d) {
	int cnt = v.size();
	for (int i = 0; i < cnt; i++) g[v[i]].clear();
	for (int i = 0; i < cnt - 3; i++) {
		int x = from[ee[i]], y = to[ee[i]];
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < cnt; i++) {
		int j = (i + 1) % cnt;
		g[v[i]].push_back(v[j]);
		g[v[j]].push_back(v[i]);
	}
	for (int i = 0; i < cnt; i++) d[i] = -1;
	int b = 0, e = 1;
	que[0] = start;
	d[pos[start]] = 0;
	while (b < e) {
		int x = que[b], sz = g[x].size();
		for (int j = 0; j < sz; j++) {
			int y = g[x][j];
			if (d[pos[y]] == -1) {
				d[pos[y]] = d[pos[x]] + 1;
				que[e++] = y;
			}
		}
		b++;
	}
}

void process(vector <int> &v, vector <int> &e, vector <int> &q) {
	if (v.size() <= 3) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			int x = qx[q[i]], y = qy[q[i]];
			res[q[i]] = (x == y ? 0 : 1);
		}
		return;
	}
	int cnt = v.size();
	for (int i = 0; i < cnt; i++) pos[v[i]] = i;
	int best = -1, fst = -1, snd = -1;
	for (int i = 0; i < cnt - 3; i++) {
		int x = from[e[i]], y = to[e[i]];
		int diff = abs(pos[x] - pos[y]);
		diff = min(diff, cnt - diff);
		if (diff > best) {
			best = diff;
			fst = min(x, y);
			snd = max(x, y);
		}
	}
	bfs(v, e, fst, d_fst);
	bfs(v, e, snd, d_snd);
	vector <int> in_v, out_v;
	for (int i = pos[fst]; i <= pos[snd]; i++) in_v.push_back(v[i]);
	for (int i = 0; i <= pos[fst]; i++) out_v.push_back(v[i]);
	for (int i = pos[snd]; i < cnt; i++) out_v.push_back(v[i]);
	vector <int> in_q, out_q;
	int qs = q.size();
	for (int i = 0; i < qs; i++) {
		int x = qx[q[i]], y = qy[q[i]];
		if (fst < x && x < snd && (fst < y && y < snd)) {
			in_q.push_back(q[i]);
			continue;
		}
		if ((fst > x || x > snd) && (fst > y || y > snd)) {
			out_q.push_back(q[i]);
			continue;
		}
		x = pos[x];
		y = pos[y];
		res[q[i]] = min(d_fst[x] + d_fst[y], d_snd[x] + d_snd[y]);
	}
	vector <int> in_e, out_e;
	for (int i = 0; i < cnt - 3; i++) {
		int x = from[e[i]], y = to[e[i]];
		if (fst < x && x < snd || fst < y && y < snd) in_e.push_back(e[i]);
		if (fst > x || x > snd || (fst > y || y > snd)) out_e.push_back(e[i]);
	}
	process(in_v, in_e, in_q);
	process(out_v, out_e, out_q);
}

int main() {
	int n;
	scanf("%d", &n);
	vector <int> root_v(n);
	vector <int> root_e(n - 3);
	for (int i = 0; i < n; i++) root_v[i] = i;
	for (int i = 0; i < n - 3; i++) root_e[i] = i;
	for (int i = 0; i < n - 3; i++) {
		scanf("%d %d", from + i, to + i);
		from[i]--; to[i]--;
	}
	int qs;
	scanf("%d", &qs);
	vector <int> root_q(qs);
	for (int i = 0; i < qs; i++) {
		scanf("%d %d", qx + i, qy + i);
		qx[i]--; qy[i]--;
		root_q[i] = i;
		res[i] = -1;
	}
	process(root_v, root_e, root_q);
	for (int i = 0; i < qs; i++) printf("%d\n", res[i]);
	return 0;
}
