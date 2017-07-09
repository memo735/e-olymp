// Time complexity: O(n/(p/100)^2)

/* Solution method:
* Select 10000 (or more) pairs of points at random, and determine the lines that go through them.
* If 20% (or more) of all points are on the same line, we expect to find it about 400 times(*).
* For all lines that we find more than 230 times (at most 43), see how many points are on it.
* Report "possible" if one of them works.
* (*) Worst case: 15 points, p=20%, exactly 3 on one line: E = 10000/35 = 285.7, sigma = 16.7
*/
#include <algorithm>
#include <math.h>
#include <iostream>
#include <map>

using namespace std;

const int N = 1000000, samples = 10000, threshold = 230;

int X[N], Y[N];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

struct line
{
	long a, b, c; // ax+by=c
	line() {}
	// Construct line through (x1,y1) and (x2,y2)
	line(int x1, int y1, int x2, int y2)
	{
		int d = gcd(abs(x1 - x2), abs(y1 - y2));
		if (x1 - x2 < 0) d = -d;
		a = -(y1 - y2) / d;
		b = (x1 - x2) / d;
		c = a*x1 + b*y1;
	}
};

bool operator < (line L1, line L2)
{
	return L1.a < L2.a || L1.a == L2.a && (L1.b < L2.b || L1.b == L2.b && L1.c < L2.c);
}

map<line, int> Cnt;

// RNG (modulo 2^32)
unsigned int randnr()
{
	static unsigned int rseed = 42;
	return rseed = 22695477 * rseed + 1;
}

int main()
{
	int n, p, i, j;
	scanf("%d %d", &n, &p);
	for (i = 0; i < n; i++) scanf("%d %d", &X[i], &Y[i]);
	if (n == 1)
	{
		printf("possible\n");
		return 0;
	}
	// Try a lot of random pairs of points
	for (int s = 0; s < samples; s++)
	{
		i = randnr() % n;
		do j = randnr() % n;
		while (j == i);
		Cnt[line(X[i], Y[i], X[j], Y[j])]++; // Add to count
	}
	// Check all lines whose count is above the threshold
	for (map<line, int>::iterator it = Cnt.begin(); it != Cnt.end(); ++it)
	{
		if (it->second > threshold)
		{
			long a = it->first.a, b = it->first.b, c = it->first.c;
			int m = 0;
			for (i = 0; i < n; i++) if (a*X[i] + b*Y[i] == c) m++;
			if (100 * m >= n*p)
			{
				printf("possible\n");
				return 0;
			}
		}
	}
	printf("impossible\n");
	return 0;
}
