#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

bool solve(int id)
{
	int n; cin >> n;
	if (!n) return false;
	cout << "Case " << id << ":";
	//contains the amount of fuel at station
	//i - fuel needed to get to next station
	int diff[MAX_N];
	for (int i = 0; i < n; i++) cin >> diff[i];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		diff[i] -= x;
	}
	int sum[MAX_N];
	partial_sum(diff, diff + n, sum);
	int worst = *min_element(sum, sum + n);
	for (int i = 0; i < n; i++) {
		if (worst >= 0) cout << ' ' << i + 1;
		worst -= diff[i];
	}
	cout << endl;
	return true;
}

int main()
{
	int id = 1;
	while (solve(id++));
	return 0;
}
