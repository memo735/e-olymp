#include <iostream>

using namespace std;

int main() {
	int n, m, x, s = 0, p = 0, res;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		if (x > p) p = x;
	}
	res = (s + m - 1) / m;
	if (res < p) res = p;
	printf("%d\n", res);
	return 0;
}
