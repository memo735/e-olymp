#include <iostream>

using namespace std;

int ans = 0, vect[4][2];

int S(int a, int b)
{
	return (vect[a][0] - vect[b][0]) * (vect[a][1] + vect[b][1]);
}

int main()
{
	for (int i = 0; i < 4; i++) cin >> vect[i][0] >> vect[i][1];
	for (int i = 1; i < 4; i++) ans += S(i - 1, i);
	ans += S(3, 0);
	if (ans < 0) ans *= -1;
	cout << ans / 2 + (ans % 2) << endl;
}
