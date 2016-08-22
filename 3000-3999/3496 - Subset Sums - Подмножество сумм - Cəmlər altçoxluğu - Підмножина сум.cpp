#include <iostream>
#include <string.h>

using namespace std;

#define MAX 1001

long i, j, n, s, m[1001];

int main() {
	scanf("%ld", &n);
	memset(m, 0, sizeof m);
	m[0] = 1;
	for (i = 1; i <= n; i++)
		for (j = MAX - 1; j >= i; j--) m[j] += m[j - i];

	//Вычисляем сумму чисел от 1 до n. Выводим результат.
	s = (1 + n) * n / 2;
	if (s % 2 == 1) printf("0\n");
	else printf("%ld\n", m[s / 2] / 2);
	return 0;
}
