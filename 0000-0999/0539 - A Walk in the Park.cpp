#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 100001;

inline long long read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x*f;
}

int n, m;

struct node
{
	int x, y, flag, id;
};

node p[maxn], l[maxn];
set<int> S, Ans;

bool cmp1(node a, node b)
{
	return a.y < b.y;
}

bool cmp2(node a, node b)
{
	return a.y > b.y;
}

bool cmp3(node a, node b)
{
	return a.x < b.x;
}

bool cmp4(node a, node b)
{
	return a.x > b.x;
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)break;
		memset(p, 0, sizeof p);
		memset(l, 0, sizeof l);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].flag = 0;
			p[i].id = i;
		}
		S.clear();
		Ans.clear();
		getchar();
		for (int i = 1; i <= m; i++)
		{
			char c = getchar();
			getchar();
			int p = read();
			if (c == 'x')
			{
				l[i].x = p;
				l[i].flag = 2;
			}
			else
			{
				l[i].y = p;
				l[i].flag = 1;
			}
		}
		vector<node> V;
		int first;
		first = 1;
		S.clear();
		V.clear();
		for (int i = 1; i <= n; i++) V.push_back(p[i]);
		for (int i = 1; i <= n; i++)
			if (l[i].flag == 1) V.push_back(l[i]);

		sort(V.begin(), V.end(), cmp1);
		for (int i = 0; i < V.size(); i++)
		{
			if (V[i].flag == 1)
			{
				S.clear();
				first = 0;
			}
			else
			{
				if (first == 1) continue;
				if (S.count(V[i].x)) continue;
				S.insert(V[i].x);
				Ans.insert(V[i].id);
			}
		}
		S.clear();
		V.clear();
		first = 1;
		for (int i = 1; i <= n; i++) V.push_back(p[i]);
		for (int i = 1; i <= n; i++)
			if (l[i].flag == 1) V.push_back(l[i]);

		sort(V.begin(), V.end(), cmp2);
		for (int i = 0; i < V.size(); i++)
		{
			if (V[i].flag == 1)
			{
				S.clear();
				first = 0;
			}
			else
			{
				if (first == 1) continue;
				if (S.count(V[i].x)) continue;
				S.insert(V[i].x);
				Ans.insert(V[i].id);
			}
		}
		S.clear();
		V.clear();
		first = 1;
		for (int i = 1; i <= n; i++) V.push_back(p[i]);
		for (int i = 1; i <= n; i++)
			if (l[i].flag == 2) V.push_back(l[i]);

		sort(V.begin(), V.end(), cmp3);
		for (int i = 0; i < V.size(); i++)
		{
			if (V[i].flag == 2)
			{
				first = 0;
				S.clear();
			}
			else
			{
				if (first == 1) continue;
				if (S.count(V[i].y)) continue;
				S.insert(V[i].y);
				Ans.insert(V[i].id);
			}
		}
		first = 1;
		S.clear();
		V.clear();
		for (int i = 1; i <= n; i++) V.push_back(p[i]);
		for (int i = 1; i <= n; i++)
			if (l[i].flag == 2) V.push_back(l[i]);

		sort(V.begin(), V.end(), cmp4);
		for (int i = 0; i < V.size(); i++)
		{
			if (V[i].flag == 2)
			{
				first = 0;
				S.clear();
			}
			else
			{
				if (first == 1) continue;
				if (S.count(V[i].y)) continue;
				S.insert(V[i].y);
				Ans.insert(V[i].id);
			}
		}
		printf("%d\n", Ans.size());
	}
	return 0;
}
