#include <iostream>

using namespace std;

double p[401];
int n;

int main() {
	p[1] = 1.0;
	for (int i = 2; i < 401; i++) p[i] = p[i - 1] * (1 - (i - 1) / 365.0);
	while (scanf("%d", &n) == 1) printf("%.8lf%%\n", (1 - p[n]) * 100);
	return 0;
}
