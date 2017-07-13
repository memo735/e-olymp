#include <iostream>
#include <vector>

using namespace std;

const int N = 10001;

int main() {
	int n, k, ans = 0, best = 1e9, pos = -1;
	int take[N], take2[N];
	scanf("%d %d", &n, &k);
	bool was[N];
	for (int i = 0; i < n; i++) {
		int x, a, b, c;
		scanf("%d %d %d %d", &x, &a, &b, &c);
		for (int j = 0; j < c; j++) was[j] = false;
		vector <int> z;
		while (!was[x]) {
			z.push_back(x);
			was[x] = true;
			x = (x * a + b) % c;
		}
		int mx = -1, mp = -1;
		for (int j = 0; j < z.size(); j++) {
			if (z[j] > mx) {
				mx = z[j];
				mp = j;
			}
		}
		int mx2 = -1, mp2 = -1;
		for (int j = 0; j < z.size(); j++) {
			if (z[j] % k != mx % k && z[j] > mx2) {
				mx2 = z[j];
				mp2 = j;
			}
		}
		take[i] = mp;
		take2[i] = mp2;
		ans += mx;
		int diff = mx - mx2;
		if (mp2 != -1 && diff < best) {
			best = diff;
			pos = i;
		}
	}
	if (ans % k == 0 && best == 1e9) {
		printf("%d\n", -1);
		return 0;
	}
	if (ans % k == 0) {
		ans -= best;
		take[pos] = take2[pos];
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		if (i > 0) putchar(' ');
		printf("%d", take[i]);
	}
	printf("\n");
	return 0;
}
