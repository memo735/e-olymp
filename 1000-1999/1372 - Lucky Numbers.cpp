#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 5000000;

int T, cnt, cnt_;
long lucky_num[MAXN];

void dfs1(long sum, int dep)
{
	if (dep == 12) return;
	lucky_num[cnt++] = sum * 10 + 4;
	dfs1(sum * 10 + 4, dep + 1);
	lucky_num[cnt++] = sum * 10 + 7;
	dfs1(sum * 10 + 7, dep + 1);
}

void dfs2(long pro, int s)
{
	for (int i = s; i < cnt_; i++)
	{
		long tmp = lucky_num[i] * pro;
		if (0 < tmp && tmp <= 1000000000000)
		{
			lucky_num[cnt++] = tmp;
			dfs2(tmp, i);
		}
		else break;
	}
}

int bsearch(int l, int r, long key)
{
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (lucky_num[mid] == key) return mid;
		if (lucky_num[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	return l;   //finally,l > r
}

int main()
{
	dfs1(0, 0);
	sort(lucky_num, lucky_num + cnt);
	cnt_ = cnt;
	dfs2(1, 0);
	sort(lucky_num, lucky_num + cnt);
	cnt = unique(lucky_num, lucky_num + cnt) - lucky_num;
	scanf("%d", &T);
	while (T--)
	{
		long a, b;
		scanf("%ld%ld", &a, &b);
		int l = bsearch(0, cnt - 1, a);
		int r = bsearch(0, cnt - 1, b);
		int ans = r - l;
		if (b == lucky_num[r]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
