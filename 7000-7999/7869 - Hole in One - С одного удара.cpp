#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pll;
const double eps = 1e-9, inf = 1e100;
pair<int, int> s, t;
int n;

struct wall {
	int x1, y1, x2, y2;
};
vector<wall> walls;

double dist(pll a, pll b) {
	double dx = a.first - b.first, dy = a.second - b.second;
	return sqrt(dx*dx + dy*dy);
}

void reflect(pll &p, wall w) {
	w.x1 == w.x2 ? p.first = 2 * w.x1 - p.first : p.second = 2 * w.y1 - p.second;
}

double intersection_time(pll p, pll v, wall w) {
	if (w.y1 == w.y2) swap(p.first, p.second), swap(v.first, v.second), swap(w.x1, w.y1), swap(w.x2, w.y2);
	if (!v.first) return inf;
	double t = double(w.x1 - p.first) / v.first, y = p.second + t*v.second;
	if (y < w.y1 - eps || y > w.y2 + eps) return inf;
	return t;
}

int cast(pair<int, int> vt)
{
	if (s == vt) return -1;
	double d = dist(s, vt);
	pair<int, int> vs = s;
	int res = -1;
	double tcur = 0;
	vector<bool> used(n);
	for (int k = 0; k < n + 1; k++) {
		pll v(vt.first - vs.first, vt.second - vs.second);
		int i = -1;
		double ti = inf;
		for (int j = 0; j < n; j++) {
			if (!used[j]) {
				double tj = intersection_time(vs, v, walls[j]);
				if (tj > tcur + eps && tj < ti) i = j, ti = tj;
			}
		}
		double tn = dist(vs, t) / d;
		if (abs(vs.first + tn*v.first - t.first) < eps &&
			abs(vs.second + tn*v.second - t.second) < eps &&
			tn > tcur + eps && tn < ti) res = k;
		if (ti == inf) break;
		used[i] = true;
		tcur = ti, reflect(vs, walls[i]), reflect(vt, walls[i]);
	}
	return res;
}

unordered_set<int> gen(int x0, vector<int> xs) {
	int k = int(xs.size());
	unordered_set<int> res;
	for (int mask = 0; mask < 1 << k; mask++) {
		for (int mask1 = mask; ; mask1 = mask1 - 1 & mask) {
			int mask2 = mask ^ mask1, x = 0;
			for (int i = 0; i < k; i++) {
				if (mask1 & 1 << i) x += 2 * xs[i];
				if (mask2 & 1 << i) x -= 2 * xs[i];
			}
			__builtin_popcount(mask) % 2 ? x -= x0 : x += x0;
			res.insert(x);
			if (!mask1) break;
		}
	}
	return res;
}

int main() {
	cin >> n;
	walls.resize(n);
	s = { 0,0 };
	cin >> t.first >> t.second;
	vector<int> xs, ys;
	for (auto &w : walls) {
		cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
		if (w.x1 > w.x2) swap(w.x1, w.x2);
		if (w.y1 > w.y2) swap(w.y1, w.y2);
		w.x1 == w.x2 ? xs.push_back(w.x1) : ys.push_back(w.y1);
	}
	int res = -1;
	unordered_set<int> vxs = gen(t.first, xs), vys = gen(t.second, ys);
	for (int x : vxs)
		for (int y : vys) res = max(res, cast({ x,y }));
	(res < 0 ? cout << "impossible" : cout << res) << endl;
	return 0;
}
