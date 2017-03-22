#include <iostream>

using namespace std;

int main()
{
	int n, t1, t2, t3;
	while (true)
	{
		cin >> n >> t1 >> t2 >> t3;
		if (n == 0 && t1 == 0 && t2 == 0 && t3 == 0) break;
		int ans = 4 * n - 1;
		ans += t2 > t1 ? t2 - t1 : n - (t1 - t2);
		ans += t3 > t2 ? n - (t3 - t2) : t2 - t3;
		cout << ans << endl;
	}
}
