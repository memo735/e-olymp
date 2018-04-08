#include <iostream>
#include <math.h>

using namespace std;

long Say(long r)
{
	long res = 0;
	for (long y = 0; y <= r; y++) res += (long)sqrt(r*r - y*y);
	return 4 * res + 1;
}

int main() {
	long n;
	scanf("%ld", &n);
	//Радиус круга, который покрывает как минимум n точек, ищем бинарным поиском.
	//Изначально положим, что он находится в интервале[l; r] = [0; 1000000].
	long l = 0, r = 1000000;

	while (l < r)
	{
		long m = (l + r) / 2;
		//Если количество точек в круге радиуса m меньше n, то увеличиваем левую границу 
		//интервала до m + 1 (радиуса m не хватит для покрытия n точек).Иначе уменьшаем правую.
		if (Say(m) < n) l = m + 1;
		else r = m;
	}
	printf("%d\n", l);
	return 0;
}
