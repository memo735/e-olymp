#include <iostream>
#include <cmath>

using namespace std;

int getMinMatches(int n) {
	int a = (int)sqrt(n);
	n -= a * a;

	int res = 2 * a * (a + 1);
	if (n == 0) return res;

	int ones = (n > a) ? 2 : 1;
	res += (n - ones) * 2 + ones * 3;

	return res;
}

int main() {
	int n;
	cin >> n;

	cout << getMinMatches(n) << endl;
	
	system("pause");
	return 0;
}
