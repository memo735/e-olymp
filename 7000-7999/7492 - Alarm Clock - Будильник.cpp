#include <iostream>

using namespace std;

int main() {
	int need;
	while (scanf("%d", &need) == 1) {
		const int cnts[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
		for (int h = 0; h < 24; h++)
			for (int m = 0; m < 60; m++) {
				int cans = 0;
				cans += cnts[h / 10];
				cans += cnts[h % 10];
				cans += cnts[m / 10];
				cans += cnts[m % 10];
				if (cans == need) {
					printf("%02d:%02d\n", h, m);
					goto end;
				}
			}
		printf("Impossible\n");
	end:;
	}
	return 0;
}
