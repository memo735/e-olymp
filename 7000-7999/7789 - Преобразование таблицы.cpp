#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000001, MAXW = 5000;

char s[MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN], pr[MAXW], pc[MAXW], table[MAXW][MAXW];

void readArray(int *a, int n, int r) {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) scanf("%d", &a[i]);
	for (int i = k; i < n; i++) a[i] = (10007L * a[i - 2] + 10009L * a[i - 1] + 87277) % r;
}

int main() {
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	scanf("%s", s);
	readArray(a, n, h);
	readArray(b, n, w);
	readArray(c, n, h);
	readArray(d, n, w);
	for (int i = 0; i < w; i++) pc[i] = i;
	for (int i = 0; i < h; i++) pr[i] = i;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) table[i][j] = i * w + j;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'c') swap(pc[b[i]], pc[d[i]]);
		else if (s[i] == 'r') swap(pr[a[i]], pr[c[i]]);
		else swap(table[pr[a[i]]][pc[b[i]]], table[pr[c[i]]][pc[d[i]]]);
	}
	int ans = 0, c = 1;
	for (int i = 0; i < h; i++) {
		int cc = c;
		for (int j = 0; j < w; j++) {
			ans = (ans + 1L * cc * table[pr[i]][pc[j]]) % 1000000007;
			cc = 19L * cc % 1000000007;
		}
		c = 17L * c % 1000000007;
	}
	printf("%d\n", ans);
	return 0;
}
