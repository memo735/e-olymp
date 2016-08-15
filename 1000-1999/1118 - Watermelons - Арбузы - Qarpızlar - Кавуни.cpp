#include <iostream>

using namespace std;

int main() {
	int n, w, mn = 1000000000, mx = 0;
	scanf("%d", &n);
	if (n < 2) printf("Ooops!\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w);
			if (w < mn) mn = w;
			if (w > mx) mx = w;
		}
		printf("%d %d\n", mn, mx);
	}
	return 0;
}
