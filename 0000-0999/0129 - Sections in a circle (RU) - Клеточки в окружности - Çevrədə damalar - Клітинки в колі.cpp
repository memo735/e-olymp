#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double R; cin >> R;
	int ans = 0;
	for (double x = 1; x < R; x = x + 1) ans += sqrt(R*R - x*x);
	ans *= 4;
	cout << ans << endl;
}
