#include <iostream> 
#include <math.h>

using namespace std; 

double kv(double x)
{
	return x*x;
}

double mesafe(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(kv(x2 - x1) + kv(y2 - y1) + kv(z2 - z1));
}

int main()
{
	double a, b, c, xA, yA, zA, xB, yB, zB, xC, yC, zC;
	cin >> xA >> yA >> zA >> xB >> yB >> zB >> xC >> yC >> zC;
	a = mesafe(xB, yB, zB, xC, yC, zC);
	b = mesafe(xA, yA, zA, xC, yC, zC);
	c = mesafe(xA, yA, zA, xB, yB, zB);
	double nisbet = kv((a + b - c)*(a + c - b)*(b + c - a) / (2 * a*b*c));
	if (nisbet < 0.001) cout << "Zero!";
	else printf("%.2lf\n", nisbet);
}
