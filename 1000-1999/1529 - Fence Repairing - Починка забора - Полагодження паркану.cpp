#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

char boards[2501];
double c[2501];

//Функция calculateCost вычисляет наименьшую стоимость починки всего забора.
double calculateCost()
{
	int i, j, len = strlen(boards + 1);
	for (c[0] = 0, i = 1; i <= len; i++)
	{
		c[i] = 2000000000;
		if (boards[i] == '.') c[i] = c[i - 1];
		else
			for (j = 0; j < i; j++) c[i] = min(c[i], c[j] + sqrt(1.0 * i - j));
	}
	return c[len];
}

int main() {
	while (gets(boards + 1)) printf("%.4lf\n", calculateCost());
	return 0;
}
