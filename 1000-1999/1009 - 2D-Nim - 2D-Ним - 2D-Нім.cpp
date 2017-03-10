#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct position {
	int x, y;
} pos[10001];


int main() {
	int T, w, h, n, map[101][101], sum[2][10001];
	cin >> T;
	while (T--) {
		cin >> w >> h >> n;
		memset(map, 0, sizeof map);
		for (int i = 1;i <= n;i++) {
			cin >> pos[i].x >> pos[i].y;
			map[pos[i].x][pos[i].y] = 1;
		}
		for (int i = 1; i <= n;i++) {
			int xx = pos[i].x, yy = pos[i].y, x, y, cnt = 0;
			for (x = xx, y = yy; map[x][y] && y < h;++y, ++cnt);
			for (x = xx, y = yy; map[x][y] && x < w;++x, ++cnt);
			for (x = xx, y = yy; map[x][y] && y >= 0;--y, ++cnt);
			for (x = xx, y = yy; map[x][y] && x >= 0;--x, ++cnt);
			sum[0][i] = cnt;
		}
		memset(map, 0, sizeof map);
		for (int i = 1;i <= n;i++) {
			cin >> pos[i].x >> pos[i].y;
			map[pos[i].x][pos[i].y] = 1;
		}
		for (int i = 1;i <= n;i++) {
			int xx = pos[i].x, yy = pos[i].y, x, y, cnt = 0;
			for (x = xx, y = yy;map[x][y] && y < h;++y, ++cnt);
			for (x = xx, y = yy;map[x][y] && x < w;++x, ++cnt);
			for (x = xx, y = yy;map[x][y] && y >= 0;--y, ++cnt);
			for (x = xx, y = yy;map[x][y] && x >= 0;--x, ++cnt);
			sum[1][i] = cnt;
		}
		sort(sum[0] + 1, sum[0] + 1 + n);
		sort(sum[1] + 1, sum[1] + 1 + n);
		int pd = 1;
		for (int i = 1;i <= n;i++)
			if (sum[0][i] != sum[1][i]) {
				pd = 0;
				break;
			}
		puts(pd ? "YES" : "NO");
	}
	return 0;
}
