#include <iostream>

using namespace std;

int main() {
	long n, p, res = 1;
	scanf("%lld", &n);
	for (int i = 2; i <= 1000; i++)
	{
		p = i;
		//Пусть i – простой делитель n. Находим максимальную
		//степень a, для которой i^a делит n.
		while (n % i == 0)
		{
			n /= i;
			p *= i;
		}
		//После выполнения цикла p = i^(a + 1).
		res *= (p - 1) / (i - 1);
	}
	printf("%ld\n", res);
	return 0;
}
