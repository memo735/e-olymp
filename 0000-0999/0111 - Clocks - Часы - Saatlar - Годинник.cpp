#include <iostream>

using namespace std;

int main() {
	int h1, m1, h2, m2, result = 0;
	cin >> h1 >> m1 >> h2 >> m2;
	while (1) {
		if (m1 == 0) result += h1 > 12 ? h1 - 12 : h1 == 0 ? 12 : h1;
		else if (m1 == 30) result++;
		if (h1 == h2 && m1 == m2) break;
		m1++;
		if (m1 == 60) {
			m1 = 0;
			h1++;
		}
	}
	cout << result << endl;
	return 0;
}
