#include <iostream>

using namespace std;

long nsd(long x, long y)
{
	while (x != 0 && y != 0)
	{
		if (x > y) x = x%y;
		else y = y%x;
	}
	return x + y;
}

int main()
{
	long x1, x2, y1, y2;
	double dx, dy;
	cin >> x1 >> y1 >> x2 >> y2;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	cout << nsd(dx, dy) + 1 << endl;
	return 0;
}
