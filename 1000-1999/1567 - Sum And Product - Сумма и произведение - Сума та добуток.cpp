#include <iostream>
#include <math.h>

using namespace std;

int smallestSet(int s, int p)
{
	int n;
	if (s == p) return 1;
	for (n = 2; n <= s; n++)
		if (pow(1.0 * s / n, n) >= p) return n;
	return -1;
}

int main() {
	int s, p;
	while (scanf("%d %d", &s, &p) == 2) printf("%d\n", smallestSet(s, p));
	return 0;
}
