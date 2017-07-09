#include <iostream>
#include <math.h>

using namespace std;

double mesafe(int x0, int y0, int x, int y)
{
	return sqrt((x - x0)*(x - x0) + (y - y0)*(y - y0));
}

int main() {
	double x0, y0, x1, y1, x2, y2;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
	double h = ((x2 - x1)*(y0 - y1) - (x0 - x1)*(y2 - y1)) / mesafe(x1, y1, x2, y2);
	printf("%.6f", h > 0 ? h : -h);
	return 0;
}
