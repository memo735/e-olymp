#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	double l, k, t1, t2, h;
	cin >> l >> k >> t1 >> t2 >> h;
	double p = h + k*(t2 + t1), f = p / 2 + sqrt(p*p / 4 - k*t1*l);
	cout << fixed << setprecision(9) << (h <= l ? h : f) << " " << (h < l ? h : f) << endl;
	return 0;
}
