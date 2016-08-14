#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 60001

int i, n, len, pos, sz, x[MAX], lis[MAX], L[MAX];

void PrintSeq(int pos)
{
	if (sz < 0) return;
	while (L[pos] != sz) pos--;
	sz--;
	PrintSeq(pos - 1);
	printf("%d ", x[pos]);
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &x[i]);
	for (len = i = 0; i < n; i++)
	{
		pos = lower_bound(lis, lis + len, x[i]) - lis;
		lis[pos] = x[i];
		L[i] = pos;
		if (pos == len) len++;
	}
	printf("%d\n", len);
	sz = len - 1;
	PrintSeq(n - 1);
	printf("\n");
	return 0;
}
