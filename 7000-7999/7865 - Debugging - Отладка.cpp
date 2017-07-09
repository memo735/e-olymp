#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//An O(n * sqrt(n)) solution

vector<long> memo;
int N;
long t_run, t_add;

long solve(int n) {
	long &answer = memo[n];
	if (answer >= 0) return answer;
	answer = 1L << 62;
	if (n == 1) return answer = 0;
	int sqrtn = int(sqrt(n) + 1);
	// try adding 1..sqrtn printfs
	for (long add = 1; add <= sqrtn; ++add) {
		long maxpart = (n + add) / (add + 1);
		answer = min(answer, t_add * add + t_run + solve(maxpart));
	}
	// try splitting into parts of size 1..sqrtn
	for (long maxpart = 1; maxpart <= sqrtn; ++maxpart) {
		if (maxpart >= n) continue;
		long add = (n - 1) / maxpart;
		answer = min(answer, t_add * add + t_run + solve(maxpart));
	}
	return answer;
}

int main() {
	cin >> N >> t_run >> t_add;
	memo.resize(N + 1, -1);
	cout << solve(N) << endl;
}
