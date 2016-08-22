#include <iostream>
#include <vector>

using namespace std;

int i, n, a, b, cnt;
vector<int> m;

int main()
{
	while (scanf("%d", &n) == 1)
	{
		m.resize(n);
		for (i = 0; i < n; i++) scanf("%d", &m[i]);
		scanf("%d %d", &a, &b);
		for (cnt = i = 0; i < n; i++)
			if (m[i] >= a && m[i] <= b) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
