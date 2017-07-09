#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, a[100001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(&a[0], &a[n]);
	int ans = a[0] + a[n - 1];
	for (int i = 0, j = n - 1; i < j; i++, j--)
		ans = (ans > a[i] + a[j]) ? a[i] + a[j] : ans;
	printf("%d\n", ans);
	return 0;
}
