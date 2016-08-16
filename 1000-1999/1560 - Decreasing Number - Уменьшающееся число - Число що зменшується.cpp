#include <iostream>
#include <algorithm>

using namespace std;

int n, d[1000001];

int numberOfOperations(int n)
{
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	return d[n];
}

int main() {
	while (scanf("%d", &n) == 1) printf("%d\n", numberOfOperations(n));
	return 0;
}
