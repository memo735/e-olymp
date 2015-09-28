#include <iostream>
#include <math.h>

using namespace std;

double a, b, c, d, K, tmp;
long long answer;

int main()
{
	cin >> a >> b >> c >> d;
	K = a*b*c / d;
	if (modf(K, &tmp) == 0) answer = a*b*c / d;
	else answer = a*b*c / d + 1;
	cout << answer << endl;
}
