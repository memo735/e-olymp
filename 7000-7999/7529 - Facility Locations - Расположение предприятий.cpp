#include <iostream>  
#include <string.h>

using namespace std;  

int main() {
	int m, n, k, vis1[20000], vis2[20000], a[200][200];
	while (scanf("%d%d%d", &m, &n, &k) != EOF)
	{
		memset(vis1, 0, sizeof vis1);
		memset(vis2, 0, sizeof vis2);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) cin >> a[i][j];
		}
		int ans = 0, flag;
		while (true)
		{
			int maxn = 0, choose = -1;
			for (int i = 0; i < m; i++)
			{
				int cnt = 0;
				if (vis2[i] == 1)continue;
				for (int j = 0; j < n; j++)
				{
					if (vis1[j] == 1) continue;
					if (a[i][j] == 0) cnt++;
				}
				if (cnt > maxn)
				{
					maxn = cnt;
					choose = i;
				}
			}
			if (choose == -1)
			{
				flag = -1;
				break;
			}
			vis2[choose] = 1;
			for (int i = 0;i < n;i++)
				if (a[choose][i] == 0)vis1[i] = 1;
			ans++;
			int p;
			for (p = 0;p < n;p++)
				if (vis1[p] == 0)break;
			if (p >= n)
			{
				flag = 1;
				break;
			}
			if (ans >= k)
			{
				flag = -1;
				break;
			}
		}
		cout << (flag == 1 ? "yes\n" : "no\n");
	}
	return 0;
}
