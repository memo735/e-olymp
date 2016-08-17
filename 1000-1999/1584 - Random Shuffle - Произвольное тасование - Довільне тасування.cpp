#include <iostream>
#include <math.h>

using namespace std;

int i, n, s, m[10], cur[10];

void shuffle(int pos)
{
	int i, c;
	if (pos == n)
	{
		for (i = 0; i < n; i++) if (m[i] != cur[i]) return;
		s++;
		return;
	}
	for (c = i = 0; i < n; i++) if (m[i] != cur[i]) c++;
	if (c > 2 * (n - pos)) return;
	for (i = 0; i < n; i++)
	{
		swap(cur[i], cur[pos]);
		shuffle(pos + 1);
		swap(cur[i], cur[pos]);
	}
}

int main() {
	while (scanf("%d", &n) == 1)
	{
		for (s = i = 0; i < n; i++) scanf("%d", &m[i]), cur[i] = i + 1;
		shuffle(0);
		printf("%.4lf\n", 1.0 * s / pow(n, n));
	}
	return 0;
}
