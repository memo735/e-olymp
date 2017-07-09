#include <limits.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

long gcd(long a, long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int N, P, R;
	cin >> N >> P >> R;
	vector<int> x(N);
	for (int n = 0; n < N; n++) cin >> x[n];
	sort(x.begin(), x.end());
	long min_sol = LONG_MAX, max_sol = 0, total_sol = 0;
	vector<int> start = x;
	start.erase(unique(start.begin(), start.end()), start.end());
	for (int i = 0; i < start.size(); i++) {
		multiset<int> todo(x.begin(), x.end());
		long sol = 0;
		int pos = start[i];
		while (!todo.empty()) {
			multiset<int>::iterator next = todo.lower_bound(pos);
			if (next != todo.end()) sol += *next - pos;
			else {
				next = todo.begin();
				sol += P - pos + *next;
			}
			pos = *next;
			todo.erase(next);
			sol += R;
			pos = (pos + R) % P;
		}
		long length = i > 0 ? start[i] - start[i - 1] : P - start.back() + start[i];
		min_sol = min(min_sol, sol);
		max_sol = max(max_sol, sol + length - 1);
		total_sol += length * sol + length * (length - 1) / 2;
	}
	cout << min_sol << endl << max_sol << endl;
	long d = gcd(total_sol, P);
	cout << total_sol / d << "/" << P / d << endl;
	return 0;
}
