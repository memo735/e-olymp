#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 2000;
const long INF = 9e18;

struct point { int x, y; };

point p[N], q[N];
int nxt[N], prv[N], good[N][N], nice[N][N];

bool inBetween(int i, int j, int k) {
	if (i <= k) return i <= j && j <= k;
	return i <= j || j <= k;
}

long vMult(point a, point b, point c) {
	return (b.x - a.x) * long(c.y - a.y) - (b.y - a.y) * long(c.x - a.x);
}

long Area(point a, point b, point c) { return abs(vMult(a, b, c)); }

long signum(long x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
		for (int i = 0; i < m; i++) scanf("%d%d", &q[i].x, &q[i].y);
		for (int i = 0; i < n; i++) {
			memset(good[i], -1, sizeof(int) * n);
			memset(nice[i], -1, sizeof(int) * n);
		}
		for (int i = 0; i < n; ++i) {
			point cur = p[i];
			point nxtPoint = *min_element(q, q + m, [cur](const point& x, const point& y) {
				return -signum(vMult(cur, x, y)) < 0;
			});

			for (nxt[i] = (i + 1) % n; vMult(cur, p[nxt[i]], nxtPoint) >= 0; nxt[i] = (nxt[i] + 1) % n);
			nxt[i] = (nxt[i] + n - 1) % n;
			point prvPoint = *max_element(q, q + m, [cur](const point& x, const point& y) {
				return -signum(vMult(cur, x, y)) < 0;
			});
			for (prv[i] = (i + n - 1) % n; vMult(cur, prvPoint, p[prv[i]]) >= 0; prv[i] = (prv[i] + n - 1) % n);
			prv[i] = (prv[i] + 1) % n;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = (i + 2) % n; j != i; j = (j + 1) % n) {
				if (inBetween(prv[j], i, j) || inBetween(i, j, nxt[i])) good[i][j] = -1;
				else if (inBetween(i, prv[j], nxt[i])) {
					good[i][j] = (Area(p[i], p[j], p[prv[j]]) > Area(p[i], p[j], p[nxt[i]])) ? nxt[i] : prv[j];
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			point cur = p[i];
			sort(q, q + m, [cur](const point& x, const point& y) {
				return -signum(vMult(cur, x, y)) < 0;
			});
			for (int j = (i + 2) % n, k = 0; j != i; j = (j + 1) % n) {
				int pj = (j + n - 1) % n;
				for (; k < m && vMult(cur, q[k], p[pj]) >= 0; ++k);
				long tmp = INF;
				if (nice[i][pj] != -1 && (k == m || vMult(cur, p[j], q[k]) > 0)) {
					nice[i][j] = nice[i][pj];
					tmp = Area(cur, p[nice[i][j]], p[good[i][nice[i][j]]]);
				}
				if (good[i][j] != -1 && tmp > Area(cur, p[j], p[good[i][j]])) nice[i][j] = j;
			}
		}
		long best = INF;
		int at = -1, a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = (i + 2) % n; j != i; j = (j + 1) % n) {
				if (nice[i][j] != -1 && nice[j][i] != -1) {
					long tmp = Area(p[i], p[nice[i][j]], p[good[i][nice[i][j]]]) +
						Area(p[j], p[nice[j][i]], p[good[j][nice[j][i]]]);
					if (tmp < best) {
						at = 2;
						best = tmp;
						a1 = i, a2 = nice[i][j], a3 = good[i][nice[i][j]];
						b1 = j, b2 = nice[j][i], b3 = good[j][nice[j][i]];
					}
				}
				if (nice[i][j] != -1 && inBetween(prv[i], j, i)) {
					long tmp = Area(p[i], p[nice[i][j]], p[good[i][nice[i][j]]]);
					if (tmp < best) {
						at = 1;
						best = tmp;
						a1 = i, a2 = nice[i][j], a3 = good[i][nice[i][j]];
					}
				}
			}
		}
		if (best == INF) puts("-1");
		else {
			printf("%d\n", at);
			printf("%d %d %d\n", a1 + 1, a2 + 1, a3 + 1);
			if (at == 2) printf("%d %d %d\n", b1 + 1, b2 + 1, b3 + 1);
		}
	}
	return 0;
}
