#include <iostream>

using namespace std;

int main()
{
	int i, j, k, n, res = 0, m[300];
	cin >> n;
	for (i = 0; i < n; i++) cin >> m[i];
	cin >> k;
	for (i = 0; i < n; i++) {
		for (j = k; j < n; j++)
			if (m[j - k] > m[j])
			{
				swap(m[j - k], m[j]);
				res++;
			}
	}
	for (i = 1; i < n; i++) if (m[i - 1] > m[i]) res = -1;
	printf("%d\n", res);
	return 0;
}
