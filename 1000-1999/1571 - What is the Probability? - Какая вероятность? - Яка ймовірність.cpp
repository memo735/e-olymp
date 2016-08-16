#include <iostream>
#include <math.h>

using namespace std;

int s, n, i;
double p;

int main() {
	scanf("%d", &s);
	while (s--)
	{
		scanf("%d %lf %d", &n, &p, &i);
		if (p < 1e-7) printf("0.0000\n");
		else printf("%.4lf\n", p*pow(1 - p, i - 1) / (1 - pow(1 - p, n)));
	}
	return 0;
}
