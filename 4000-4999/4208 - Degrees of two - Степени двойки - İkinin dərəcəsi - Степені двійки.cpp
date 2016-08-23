#include <iostream>
#include <algorithm>

using namespace std;

int d1, d2, n1, n2;

int main() {
	scanf("%d %d", &n1, &n2); n1--;
	d1 = (int)(n1*log10(2) + 1);
	d2 = (int)(n2*log10(2) + 1);
	printf("%d\n", d2 - d1);
	return 0;
}
