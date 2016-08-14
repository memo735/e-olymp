#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int> > v;
	int a, b, n, x;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		v[i] = make_pair(x, i + 1);
	}
	sort(v.begin(), v.end());
	int res = 2e9;
	for (int i = 1; i < n; i++)
		if (v[i].first - v[i - 1].first < res)
		{
			res = v[i].first - v[i - 1].first;
			a = v[i].second;
			b = v[i - 1].second;
		}

	printf("%d\n%d %d\n", res, a, b);
	return 0;
}
