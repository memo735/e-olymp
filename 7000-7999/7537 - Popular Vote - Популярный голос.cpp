#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int tot = 0, mx = -1, id = 0, num = 0, n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int x; cin >> x;
			tot += x;
			if (x > mx) mx = x, id = i, num = 1;
			else if (x == mx) ++num;
		}
		if (num > 1) cout << "no winner" << endl;
		else if (2 * mx <= tot) cout << "minority winner " << id << endl;
		else cout << "majority winner " << id << endl;
	}
	return 0;
}
