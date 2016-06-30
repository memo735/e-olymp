#include <iostream>

using namespace std;

bool checker(int param)
{
	if (param == 2) return true;
	if (!(param % 2)) return false;
	for (int i = 3; i*i <= param; i += 2) if (!(param % i)) return false;
	return true;
}

int main()
{
	int n, a = 1, b = 2, cnt = 0; cin >> n;
	while (cnt != n)
	{
		if (checker(b)) cnt++;
		b += a;
		a = b - a;
	}
	cout << a << endl;
}
