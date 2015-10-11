#include <iostream>
#include <vector>

using namespace std;

vector<int> a[100000];
bool used[100000];

void dfs(int b)
{
	used[b] = 1;
	for (int i = 0; i < a[b].size(); ++i)
	{
		int to = a[b][i];
		if (!used[to]) dfs(to);
	}
}

int main()
{
	int res = 0, n, s, k, x, y;
	cin >> n >> s >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> x >> y;
		x--; y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i < n; ++i)
	{
		if (used[i] == 0)
		{
			dfs(i);
			res++;
		}
	}
	cout << res - 1 << endl;
	return 0;
}
