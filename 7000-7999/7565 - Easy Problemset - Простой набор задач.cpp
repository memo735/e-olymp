#include <iostream>

using namespace std;

int main() {
	int n, k, cnt[42], a[42][42], pos[42];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", cnt + i);
		for (int j = 0; j < cnt[i]; j++) scanf("%d", a[i] + j);
		pos[i] = 0;
	}
	int ans = 0, i = 0;
	for (int it = 0; it < 1000; it++) {
		if (k == 0) break;
		int x = (pos[i] < cnt[i] ? a[i][pos[i]++] : 50);
		if (x >= ans) {
			ans += x;
			k--;
		}
		i = (i + 1) % n;
	}
	printf("%d\n", ans + k * 50);
	return 0;
}
