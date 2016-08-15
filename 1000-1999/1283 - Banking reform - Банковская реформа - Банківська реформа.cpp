#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 7500
int n, mas[MAX], coins[11] = { 1,5,10,25,50 };

int main() {
	memset(mas, 0, sizeof mas);
	mas[0] = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = coins[i]; j < MAX; j++) mas[j] += mas[j - coins[i]];
	}
	while (scanf("%d", &n) == 1) printf("%d\n", mas[n]);
	return 0;
}
