#include <iostream>
#include <vector>

using namespace std;

#define f first
#define s second

const int INF = 1e9 + 7;

int n, m, dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
vector<vector<char>> field;

bool on_field(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

vector<vector<int>> nearest[4];
pair<int, int> nearest_pos(int d, int x, int y) {
	return{ x + nearest[d][x][y] * dx[d], y + nearest[d][x][y] * dy[d] };
}

char buf[1000001];

int main() {
	scanf("%d%d", &n, &m);
	field.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		field[i].assign(buf, buf + m);
	}
	for (int d = 0; d < 4; d++) {
		nearest[d].resize(n);
		for (int i = 0; i < n; i++) nearest[d][i].resize(m);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int d = 0; d < 2; ++d) {
				int nx = i + dx[d], ny = j + dy[d];
				if (on_field(nx, ny)) {
					if (field[nx][ny] != field[i][j]) nearest[d][i][j] = 1;
					else nearest[d][i][j] = nearest[d][nx][ny] + 1;
				}
				else nearest[d][i][j] = INF;
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			for (int d = 2; d < 4; ++d) {
				int nx = i + dx[d], ny = j + dy[d];
				if (on_field(nx, ny)) {
					if (field[nx][ny] != field[i][j]) nearest[d][i][j] = 1;
					else nearest[d][i][j] = nearest[d][nx][ny] + 1;
				}
				else nearest[d][i][j] = INF;
			}
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		int best = INF;
		pair<pair<int, int>, pair<int, int>> mem;
		for (int d1 = 0; d1 < 4; ++d1) {
			int nx1 = x + dx[d1], ny1 = y + dy[d1];
			if (!on_field(nx1, ny1)) continue;
			//for (int d2 = (d1 + 3) % 4, cnt = 0; cnt < 2; ++cnt, d2 = (d2 + 2) % 4) {
			int d2 = d1 + 1 == 4 ? 0 : d1 + 1;
			int nx2 = x + dx[d2], ny2 = y + dy[d2];
			if (on_field(nx2, ny2)) {
				if (field[nx1][ny1] != field[nx2][ny2]) {
					best = 2;
					mem = { { nx1, ny1 },{ nx2, ny2 } };
				}
				else {
					int tmp = nearest[d1][nx1][ny1] + 1;
					if (tmp < best) {
						best = tmp;
						mem = { nearest_pos(d1, nx1, ny1),{ nx2, ny2 } };
					}
					tmp = nearest[d2][nx2][ny2] + 1;
					if (tmp < best) {
						best = tmp;
						mem = { { nx1, ny1 }, nearest_pos(d2, nx2, ny2) };
					}
				}
			}
		}
		if (best < INF) cout << mem.f.f + 1 << " " << mem.f.s + 1 << " " << mem.s.f + 1 << " " << mem.s.s + 1 << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}
