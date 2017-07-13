#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int id = 1, L, P, V;
	while (cin >> L >> P >> V && (L || P || V)) {
		cout << "Case " << id++ << ": ";
		int ans = V / P * L + min(V % P, L);
		cout << ans << endl;
	}
	return 0;
}
