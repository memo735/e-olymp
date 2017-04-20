#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double x;
	while (cin)
	{
		cin >> x;
		if (cin) printf("%.6f\n", sin(x) + sqrt(log(3 * x) / log(4)) + ceil(3 * exp(x)));
	}
	return 0;
}
