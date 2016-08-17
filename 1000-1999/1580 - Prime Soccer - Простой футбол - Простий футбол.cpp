#include <iostream>
#include <math.h>

using namespace std;

int i, skillOfTeamA, skillOfTeamB, primes[7] = { 2, 3, 5, 7, 11, 13, 17 };

double fact(int x)
{
	double y = 1;
	for (int j = 2; j <= x; ++j) y *= j;
	return y;
}

double getProbability(int skillA, int skillB)
{
	double pa, pb, f18 = fact(18), sa = skillA / 100.0, sb = skillB / 100.0;
	for (pa = pb = i = 0; i < 7; i++)
	{
		pa += f18 / fact(primes[i]) / fact(18 - primes[i]) * pow(sa, primes[i]) * pow(1 - sa, 18 - primes[i]);
		pb += f18 / fact(primes[i]) / fact(18 - primes[i]) *
			pow(1.0 * sb, primes[i]) * pow(1.0 - sb, 18 - primes[i]);
	}
	return pa + pb - pa * pb;
}

int main() {
	while (scanf("%d %d", &skillOfTeamA, &skillOfTeamB) == 2)
	{
		printf("%.4lf\n", getProbability(skillOfTeamA, skillOfTeamB));
	}
	return 0;
}
