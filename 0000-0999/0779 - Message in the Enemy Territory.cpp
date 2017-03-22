#include <algorithm>
#include <iostream>
#include <iterator>
#include <assert.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int MAXC = 1001;
bool blocked[MAXC][MAXC];
vector<int> YgivenX[MAXC], XgivenY[MAXC];

bool inside(int x, int y) { return 0 <= x && x < MAXC && 0 <= y && y < MAXC; }

void markCorner(int x, int y, int m) {
	for (int xx = x - m; xx <= x + m; ++xx) {
		for (int yy = y - m; yy <= y + m; ++yy) {
			if (!inside(xx, yy)) continue;
			if ((xx - x) * (xx - x) + (yy - y) * (yy - y) <= m * m) blocked[xx][yy] = true;
		}
	}
}

void markHorizontalLine(int x0, int x1, int y, int m) {
	for (int xx = x0; xx <= x1; ++xx) {
		for (int yy = y - m; yy <= y + m; ++yy) {
			if (!inside(xx, yy)) continue;
			blocked[xx][yy] = true;
		}
	}
}

void markVerticalLine(int y0, int y1, int x, int m) {
	for (int yy = y0; yy <= y1; ++yy) {
		for (int xx = x - m; xx <= x + m; ++xx) {
			if (!inside(xx, yy)) continue;
			blocked[xx][yy] = true;
		}
	}
}

bool canReach(int sx, int sy, int fx, int fy) {
	assert(inside(sx, sy) && (fx, fy));
	assert(!blocked[sx][sy]);
	assert(!blocked[fx][fy]);
	queue< pair< int, int > > q;
	blocked[sx][sy] = true;
	q.push(make_pair(sx, sy));
	while (q.size()) {
		int cx = q.front().first, cy = q.front().second;
		if (cx == fx && cy == fy) return true;
		q.pop();
		assert(blocked[cx][cy]);
		for (int dx = -1; dx <= +1; dx++) {
			for (int dy = -1; dy <= +1; dy++) {
				int nx = cx + dx;
				int ny = cy + dy;
				if (!inside(nx, ny)) continue;
				if (blocked[nx][ny]) continue;
				blocked[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return false;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		assert(n % 2 == 0);
		for (int i = 0; i < MAXC; ++i) YgivenX[i].clear(), XgivenY[i].clear();
		memset(blocked, 0, sizeof blocked);
		for (int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			XgivenY[y].push_back(x);
			YgivenX[x].push_back(y);
		}
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = 0; x < MAXC; ++x) {
			sort(YgivenX[x].begin(), YgivenX[x].end());
			assert(YgivenX[x].size() % 2 == 0);
			for (int k = 0; k < YgivenX[x].size(); k += 2) {
				int y = YgivenX[x][k], nextY = YgivenX[x][k + 1];
				markVerticalLine(y, nextY, x, m);
				markCorner(x, y, m);
				markCorner(x, nextY, m);
			}
		}
		for (int y = 0; y < MAXC; ++y) {
			sort(XgivenY[y].begin(), XgivenY[y].end());
			assert(XgivenY[y].size() % 2 == 0);
			for (int k = 0; k < XgivenY[y].size(); k += 2) {
				int x = XgivenY[y][k], nextX = XgivenY[y][k + 1];
				markHorizontalLine(x, nextX, y, m);
				markCorner(x, y, m);
				markCorner(nextX, y, m);
			}
		}
		puts(canReach(x1, y1, x2, y2) ? "Yes" : "No");
	}
	return 0;
}
