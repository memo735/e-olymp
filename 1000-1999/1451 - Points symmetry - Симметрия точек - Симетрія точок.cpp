#include <iostream>

using namespace std;

int main() {
	int n, p, q, pp = 0, qq = 0, dir = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p, &q);
		pp += p * dir; qq += q * dir;
		dir = -dir;
	}
	//Если n нечетно, то выводим неподвижную точку (pp, qq).
	if (n % 2) printf("%d %d\n", pp, qq);
	else
	{
		//Если n четно, то лишь при (pp, qq) = (0, 0), то любая точка плоскости является неподвижной.
		//Если хотя бы одно из значений pp или qq отлично от нуля, то неподвижных точек нет.
		if (pp || qq) printf("-1\n");
		else printf("0\n");
	}
	return 0;
}
