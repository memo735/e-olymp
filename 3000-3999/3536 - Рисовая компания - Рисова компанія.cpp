#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 1001

int main()
{
	int i, j, n, m, t, d[MAX], d1[MAX], d2[MAX], a[MAX][MAX], z[MAX][MAX];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) scanf("%d", &a[i][j]);

	scanf("%d", &t);
	while (t--)
	{
		int ans = 0, cur;
		scanf("%d", &cur);
		fill_n(d, m, -1);
		fill_n(d1, m, 0);
		fill_n(d2, m, 0);
		stack<int> st;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) z[i][j] = a[i][j] != cur;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++) if (z[i][j] == 1) d[j] = i;
			while (!st.empty()) st.pop();
			for (j = 0; j < m; j++)
			{
				while (!st.empty() && d[st.top()] <= d[j]) st.pop();
				d1[j] = st.empty() ? -1 : st.top();
				st.push(j);
			}
			while (!st.empty()) st.pop();
			for (j = m - 1; j >= 0; j--)
			{
				while (!st.empty() && d[st.top()] <= d[j]) st.pop();
				d2[j] = st.empty() ? m : st.top();
				st.push(j);
			}
			for (j = 0; j < m; j++) ans = max(ans, (i - d[j]) * (d2[j] - d1[j] - 1));
		}
		printf("%d\n", ans);
	}
	return 0;
}
