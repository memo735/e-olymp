#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 601, INF = 10000000;

int main() {
	int n, k, cnt[MAXN], g[MAXN][MAXN], know[MAXN][MAXN];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			int a;
			scanf("%d", &a);
			cnt[--a]++;
			know[i][a] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			int onlyi, onlyj, common = onlyi = onlyj = 0;
			for (int t = 0; t < n; t++) {
				if (know[t][i] && know[t][j]) common++;
				if (know[t][i] && !know[t][j]) onlyi++;
				if (!know[t][i] && know[t][j]) onlyj++;
			}
			if (!common) g[i][j] = g[j][i] = INF;
			else g[i][j] = onlyj, g[j][i] = onlyi;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (know[i][j]) g[i + k][j] = cnt[j], g[j][i + k] = 0;
			else g[i + k][j] = g[j][i + k] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) g[i + k][j + k] = INF * (i != j);
	}
	for (int t = 0; t < n + k; t++) {
		for (int i = 0; i < n + k; i++) {
			for (int j = 0; j < n + k; j++) g[i][j] = min(g[i][j], g[i][t] + g[t][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", g[i + k][j + k] == INF ? -1 : g[i + k][j + k], " \n"[j == n - 1]);
		}
	}
	return 0;
}
