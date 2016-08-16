#include <iostream>

using namespace std;

long n, cat[51];

//Используя рекуррентную формулу f(p) =sum(i=0..p-1) f(i)*f(p-i-1),
//функция countPerfect вычисляет числа Каталана от нулевого до n-го.
void countPerfect(int n)
{
	cat[0] = cat[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < i; j++)
			cat[i] += cat[j] * cat[i - j - 1];
}

int main() {
	countPerfect(50);
	while (scanf("%d", &n) == 1) printf("%ld\n", cat[n / 2]);
	return 0;
}
