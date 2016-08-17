#include <iostream>
#include <algorithm>

using namespace std;

int n;
double r[1000001];

double expectedThrows(int candies)
{
	int i, j;
	double s;
	r[0] = 0;
	for (i = 1; i <= candies; i++)
	{
		for (s = 0, j = max(i - 6, 0); j < i; j++) s += r[j];
		r[i] = 1 + s / 6;
	}
	return r[candies];
}

int main() {
	while (scanf("%d", &n) == 1) printf("%.4lf\n", expectedThrows(n));
	return 0;
}
