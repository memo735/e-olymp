#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int MaxN = 50;

int next_[MaxN*MaxN], board[MaxN][MaxN];
bool used[MaxN*MaxN];
vector<int> g[MaxN * MaxN];

bool try_kuhn(int v)
{
	if (used[v])  return false;
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		bool f = (next_[to] == -1);
		if (!f) f = try_kuhn(next_[to]);
		if (f)
		{
			next_[to] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	char c;
	int n, m, empt = 0;
	cin >> n >> m;
	memset(board, -1, sizeof board);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			if (c == '.') { board[i][j] = 0; empt++; }
			else board[i][j] = 1;
		}
	if (empt % 2)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (board[i][j] == 0 && ((i & 1) == (j & 1)))
			{
				int u = (i - 1)*m + j - 1;
				if (board[i][j - 1] == 0) g[u].push_back(u - 1);
				if (board[i][j + 1] == 0) g[u].push_back(u + 1);
				if (board[i - 1][j] == 0) g[u].push_back(u - m);
				if (board[i + 1][j] == 0) g[u].push_back(u + m);
			}
	}
	int sum = 0;
	memset(next_, -1, sizeof next_);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (board[i][j] == 0 && (i & 1) == (j & 1))
			{
				memset(used, 0, sizeof used);
				if (try_kuhn((i - 1)*m + j - 1)) sum++;
			}
	}
	if (sum * 2 == empt) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
