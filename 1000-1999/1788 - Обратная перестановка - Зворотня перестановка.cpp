#include <iostream>

using namespace std;

int main() {
	int i, x, N, a[20000];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		a[x - 1] = i + 1;
	}
	for (i = 0; i < N; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
