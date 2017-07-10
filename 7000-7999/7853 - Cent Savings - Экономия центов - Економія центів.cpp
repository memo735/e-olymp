#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	int I, D, prices[2001], dp[21];
	cin >> I >> D;
	for (int i = 0; i < I; i++) cin >> prices[i];
	dp[0] = 0; // cost is zero with 0 divider
	for (int i = 1; i < D + 1; i++) dp[i] = INT_MAX / 2; // you have to place less dividers first
	for (int i = 0; i < I; i++) {
		for (int j = D + 1 - 1; j >= 1; j--)
			// either just add item or place divider after item
			dp[j] = min(dp[j] + prices[i], (dp[j - 1] + prices[i] + 5) / 10 * 10); 
		dp[0] += prices[i]; // no divider, no choice
	}
	int mini = INT_MAX / 2;
	for (int i = 0; i < D + 1; i++) mini = min(mini, dp[i]);
	cout << (mini + 5) / 10 * 10 << endl;
	return 0;
}
