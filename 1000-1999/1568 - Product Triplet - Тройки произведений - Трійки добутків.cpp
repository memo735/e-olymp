#include <iostream>
#include <algorithm>

using namespace std;

long f(long x0, long miny, long maxy, long minz, long maxz)
{
	minz = max(minz, x0 * x0 + 1);
	if (maxz < minz) return 0;
	miny = max(miny, (minz + x0 - 1) / x0);
	maxy = min(maxy, maxz / x0);
	return max(0L, maxy - miny + 1);
}

long countTriplets(int minx, int maxx, int miny, int maxy, int minz, int maxz)
{
	long x0, y0, i, res = 0;
	for (x0 = minx; x0 <= maxx && x0 * x0 < maxz; x0++) res += f(x0, miny, maxy, minz, maxz);
	for (y0 = miny; y0 <= maxy && y0 * y0 < maxz; y0++) res += f(y0, minx, maxx, minz, maxz);
	for (i = max(minx, miny); i <= min(maxx, maxy) && i * i <= maxz; i++) if (minz <= i * i) res++;
	return res;
}

int main() {
	int minx, maxx, miny, maxy, minz, maxz;
	while (scanf("%d %d %d %d %d %d", &minx, &maxx, &miny, &maxy, &minz, &maxz) == 6)
	{
		printf("%ld\n", countTriplets(minx, maxx, miny, maxy, minz, maxz));
	}
	return 0;
}
