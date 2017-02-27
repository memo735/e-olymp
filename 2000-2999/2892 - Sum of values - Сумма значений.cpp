#include <iostream>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	double x, tam = 0.0, kesr = 0.0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &x);
		tam += x;
		kesr += 1.0 / x;
	}
	printf("%.12lf\n", tam + kesr);
	return 0;
}
