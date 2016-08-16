#include <iostream>

using namespace std;

int main() {
	int cows, cars, doors, shown;
	double res;
	while (scanf("%d %d %d", &cows, &cars, &shown) == 3)
	{
		doors = cows + cars;
		res = ((cars - 1.0)*cars + cars*cows) / (doors*(doors - shown - 1.0));
		printf("%.5lf\n", res);
	}
	return 0;
}
