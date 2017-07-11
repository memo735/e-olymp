#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
	int n, f[200001], d[200001], v[200001];
	while (scanf("%d", &n) != EOF)
	{
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		memset(v, 0, sizeof(v));
		for (int i = 1;i <= n;i++)
		{
			scanf("%d", &v[i]);
			d[v[i]]++;
		}
		for (int i = n + 1;i <= 2 * n;i++)
		{
			scanf("%d", &v[i]);
			d[v[i]]++;
		}
		for (int i = 1;i <= 2 * n;i++) if (!d[i]) q.push(i);
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			f[now] = 1;
			if (f[v[now]] == -1) continue;
			f[v[now]] = -1;
			d[v[v[now]]]--;
			if (!d[v[v[now]]]) q.push(v[v[now]]);
		}
		for (int i = 1;i <= 2 * n;i++)
		{
			if (f[i] == 1) printf("%d ", i);
			else if (i <= n && f[i] == 0) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
