#include <iostream>

using namespace std;

long n, rep[31], nonrep[31];

//Заполняем ячейки массивов rep и nonrep согласно выше приведенным формулам.
long countNotForbidden(int n)
{
	int i;
	rep[1] = 0; rep[2] = 3;
	nonrep[1] = 3; nonrep[2] = 6;
	for (i = 3; i <= n; i++)
	{
		rep[i] = rep[i - 1] + nonrep[i - 1];
		nonrep[i] = 2 * rep[i - 1] + nonrep[i - 1];
	}
	return rep[n] + nonrep[n];
}

int main() {
	while (scanf("%d", &n) == 1) printf("%ld\n", countNotForbidden(n));
	return 0;
}
