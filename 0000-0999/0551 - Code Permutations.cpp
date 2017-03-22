#include <assert.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
const long MOD = (1L << 31) - 1;

void factor(int n, vi &f) {
	for (int r = 2; r <= (n + r - 1) / r; ++r)
		while (n % r == 0) f.push_back(r), n /= r;
	if (n > 1) f.push_back(n);
}

void divisor(const vi f, int i, int v, vi &d) {
	if (i == f.size()) d.push_back(v);
	else {
		int j;
		for (j = i; j < f.size() && f[j] == f[i]; ++j);
		for (int r = 0; r <= j - i; v *= f[i], ++r) divisor(f, j, v, d);
	}
}

vi facs, facps, divs;

long mul(int l, int h) {
	long r = 1;
	for (int i = l; i <= h; ++i) r = r*i % MOD;
	return r;
}

long K, ways[150][1 << 10];
int N;

int Cover(int d) {
	int r = 0;
	for (int i = 0; i < facps.size(); ++i) if (d % facps[i] == 0) r |= 1 << i;
	return r;
}

long Ways(int n, int m) {
	if (!n) return m == 0;
	long &res = ways[n][m];
	if (res == -1) {
		res = 0;
		for (vi::iterator it = divs.begin(); it != divs.end() && *it <= n; ++it)
			res = (res + mul(n - *it + 1, n - 1) * Ways(n - *it, m & ~Cover(*it))) % MOD;
	}
	return res;
}

int main() {
	scanf("%d%ld", &N, &K);
	assert(1 <= N && N <= 100);
	assert(1 <= K && K <= MOD);
	factor(K, facs);
	for (int i = 0, j, v; i < facs.size(); ) {
		for (v = 1, j = i; j < facs.size() && facs[j] == facs[i]; v *= facs[i], ++j);
		facps.push_back(v);
		i = j;
	}
	divisor(facs, 0, 1, divs);
	sort(divs.begin(), divs.end());
	memset(ways, -1, sizeof ways);
	printf("%ld\n", Ways(N, (1 << facps.size()) - 1));
	return 0;
}
