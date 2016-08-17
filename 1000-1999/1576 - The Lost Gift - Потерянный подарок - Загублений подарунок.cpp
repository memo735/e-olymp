#include <iostream>
#include <math.h>

using namespace std;

int b, r;

// - 1 red invalid
// - 2 black invalid

int check(int bres)
{
	if (bres % 2) return -1;
	bres /= 2;
	if (!(0.7 * bres <= b && b <= bres)) return -2;
	return bres - b;
}

int main() {

	while (scanf("%d %d", &r, &b), r + b)
	{
		//Вычисляем дискриминант d квадратного уравнения. Если он не является
		//полным квадратом, то количество красных шариков не корректно.
		int d = 1 + 8 * r, dd = (int)sqrt(d);
		if (dd * dd == d)
		{
			//Вычисляем корни квадратного уравнения res1 и res2. Выводим результат в зависимости от их значения.
			int res1 = check(1 + 2 * r - dd);
			int res2 = check(1 + 2 * r + dd);
			if (res1 == -1 && res2 == -1) printf("No. of red balls invalid\n");
			else
				if (res1 == -2 && res2 == -2) printf("No. of black balls invalid\n");
				else
				{
					if (res1 >= 0 && res2 >= 0) printf("%d %d\n", res1, res2);
					else printf("%d\n", res1 >= 0 ? res1 : res2);
				}
		}
		else printf("No. of red balls invalid\n");
	}
	return 0;
}
