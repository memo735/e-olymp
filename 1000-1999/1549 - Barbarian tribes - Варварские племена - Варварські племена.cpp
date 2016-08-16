#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	while (scanf("%d %d %d", &n, &m, &k), n + m + k)
	{
		printf(m % 2 ? "Keka\n" : "Gared\n");
	}
	return 0;
}
