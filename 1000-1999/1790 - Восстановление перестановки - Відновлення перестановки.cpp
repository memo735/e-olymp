#include <iostream>

using namespace std;

int N, a[2000], b[2000], f[2000];

int get(int x) {
	for (int i = N - 1; i >= 0; i--) {
		x -= b[i];
		if (!x) {
			b[i] = 0;
			return i + 1;
		}
	}
	return 0;
}

int main() {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &f[i]);
		b[i] = 1;
	}
	for (i = N - 1; i >= 0; i--) a[i] = get(f[i] + 1);
	for (i = 0; i < N; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
