#include <iostream>

using namespace std;

int main() {
	int n, say = 0, cem = 0, a[101]; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		cem += a[i];
	}
	double orta = 1.0*cem / n;
	cem = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > orta) {
			cem += a[i];
			say++;
		}
	}
	cout << cem << " " << say;
	return 0;
}
