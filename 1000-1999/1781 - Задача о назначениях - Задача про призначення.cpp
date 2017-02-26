#include <iostream>
#include <algorithm>

using namespace std;

int solvePerm(int n, int cost[11][11])
{
	int work[11]; //[ishci] -> ish
	for (int i = 0; i < n; ++i) work[i] = i;
	int minSum = 1e7;
	do
	{
		int sum = 0;
		for (int worker = 0; worker < n; ++worker) sum += cost[worker][work[worker]];
		minSum = min(minSum, sum);
	} while (next_permutation(work, work + n));
	return minSum;
}

int main() {
	int n, cost[11][11]; cin >> n; //isci, ish
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) cin >> cost[i][j];
	}
	cout << solvePerm(n, cost);
	return 0;
}
