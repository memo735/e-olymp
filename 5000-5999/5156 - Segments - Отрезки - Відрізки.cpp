#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001
int i, n, res, test = 1;
int Sol[MAX], Sag[MAX], alLeft[MAX], alRight[MAX];

int main() {
	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &Sol[i], &Sag[i]);
			alLeft[i] = Sol[i]; alRight[i] = Sag[i];
		}
		//Сортируем левые и правые концы отрезков в отдельных массивах.
		sort(alLeft, alLeft + n);
		sort(alRight, alRight + n);
		printf("Case %d:", test++);
		for (i = 0; i < n; i++)
		{
			res = upper_bound(alLeft, alLeft + n, Sag[i]) - alLeft;
			res -= lower_bound(alRight, alRight + n, Sol[i]) - alRight;
			printf(" %d", res - 1);
		}
		printf("\n");
	}
	return 0;
}
