// Time complexity: O(n*2^n + n^2*n!/(n/2)!*log(n))
// Memory: O(n^2 + (n/2)!)

#include <algorithm>
#include <iostream>

using namespace std;

const int nmax = 14;

long Dis[nmax][nmax], Trip1[720], Trip2[720]; // array sizes: (ceil(nmax/2-1))!

// Considers all permutations of points in subset s as intermediate stops between 0 and p;
// stores distances in Trip[] and returns number of permutations
int tryallperms(int n, int p, int s, long Trip[])
{	// Base case
	if (s == 0)
	{
		Trip[0] = Dis[0][p];
		return 1;
	}
	int m = 0, i, k = 0, Point[nmax / 2];
	// Dissect subset
	for (i = 1; i < n; i++) if (s & 1 << i) Point[k++] = i;
	do
	{
		long d = Dis[0][Point[0]];
		for (i = 1; i < k; i++) d += Dis[Point[i - 1]][Point[i]];
		d += Dis[Point[k - 1]][p];
		Trip[m++] = d;
	} while (next_permutation(Point, Point + k));
	return m;
}

int main()
{
	int n, i, j;
	long L;
	scanf("%d %ld", &n, &L);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) scanf("%ld", &Dis[i][j]);

	// 0 = start point, p = mid point
	for (int p = 1; p < n; p++)
	{
		int q = (p == 1 ? 2 : 1); // Arbitrary other point
		// Try all subsets of size n/2-1 that do not involve 0, p or q
		for (int s = 0; s < 1 << n; s += 2)
			if (!(s & 1 << p) && !(s & 1 << q) && __builtin_popcount(s) == n / 2 - 1)
			{
				int m1 = tryallperms(n, p, s, Trip1);
				// Invert subset (ignoring 0 and p)
				int m2 = tryallperms(n, p, s ^ (1 << n) - 2 ^ 1 << p, Trip2);
				// See if two trip lengths combined give L
				sort(Trip1, Trip1 + m1);
				sort(Trip2, Trip2 + m2);
				for (i = 0, j = m2 - 1; i < m1 && j >= 0;)
				{
					if (Trip1[i] + Trip2[j] < L) i++;
					else if (Trip1[i] + Trip2[j] > L) j--;
					else
					{
						printf("possible\n");
						return 0;
					}
				}
			}
	}
	printf("impossible\n");
	return 0;
}
