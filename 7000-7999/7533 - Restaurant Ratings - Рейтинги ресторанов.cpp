#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

long comb(long n, long k) {
	if (k > n) return 0;
	long r = 1;
	for (long d = 1; d <= k; ++d) {
		r *= n--;
		r /= d;
	}
	return r;
}

int main() {
	int n; cin >> n;
	while (n) {
		int sum = 0;
		vector <int> val(n);
		for (int i = 0; i < n; i++) {
			cin >> val[i];
			sum += val[i];
		}
		long res = 1;
		if (sum != 0) {
			for (int i = sum - 1; i >= 1; i--) {
				long temp = comb(i + n - 1, n - 1);
				res += temp;
			}
			int c = 0;
			for (int i = 0; i < n - 1;i++) {
				if (i != 0) c += val[i - 1];
				for (int j = val[i] - 1; j >= 0;j--) {
					int num = sum - j - c + n - 1 - (i + 1);
					int den = n - 1 - (i + 1);
					long temp = comb(num, den);
					res += temp;
				}
			}
			res += 1;
		}
		cout << res << endl;
		cin >> n;
	}
	return 0;
}
