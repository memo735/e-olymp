#include <iostream>
#include <string.h>  
#include <algorithm>

using namespace std;

struct node
{
	int u, v, w;
} e[100001];

int n, m, p, father[1001], vis[1001], cnt[1001];

int cmp(node a, node b)
{
	return a.w < b.w;
}

int find(int x)
{
	if (x == father[x]) return x;
	return father[x] = find(father[x]);
}

int main()
{
	int i, x, y, u, v, w, ans;
	while (~scanf("%d%d%d", &n, &m, &p))
	{
		int flag = ans = 0;
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);
		for (i = 1; i <= n; i++) father[i] = i;
		for (i = 1; i <= p; i++)
		{
			scanf("%d", &x);
			vis[x] = 1;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			e[i].u = u;
			e[i].v = v;
			e[i].w = w;
		}
		if (n == 2)
		{
			printf("%d\n", w);
			continue;
		}
		sort(e + 1, e + 1 + m, cmp);
		for (i = 1; i <= m; i++)
		{
			u = e[i].u, v = e[i].v, w = e[i].w;
			if (vis[u] || vis[v]) continue;
			x = find(u), y = find(v);
			if (x == y) continue;
			father[x] = y;
			ans += w;
		}
		for (i = 1; i <= m; i++)
		{
			u = e[i].u, v = e[i].v, w = e[i].w;
			if (!(vis[u] ^ vis[v])) continue;
			cnt[u]++;
			cnt[v]++;
			if (vis[u] && cnt[u] >= 2) continue;
			if (vis[v] && cnt[v] >= 2) continue;
			x = find(u), y = find(v);
			if (x == y) continue;
			father[x] = y;
			ans += w;
		}
		for (i = 1; i <= n; i++) if (father[i] == i) flag++;
		flag >= 2 ? printf("impossible\n") : printf("%d\n", ans);
	}
	return 0;
}
