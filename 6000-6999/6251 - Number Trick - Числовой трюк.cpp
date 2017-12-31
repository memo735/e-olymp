#include <iostream>
#include <algorithm>

using namespace std;

#define EPS 0.000001

int main() {
	double x; scanf("%lf", &x);
	long p = 1; 
	bool flag = true;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			const int a = j * (p * 10 - 1) / (10 - x) + 0.5;
			if (a / p == j && abs((a - j * p) * 10 + j - x * a) < EPS)
			{
				printf("%d\n", a);
				flag = false;
			}
		}
		p = p * 10;
	}
	if (flag) printf("No solution\n");
	return 0;
}
