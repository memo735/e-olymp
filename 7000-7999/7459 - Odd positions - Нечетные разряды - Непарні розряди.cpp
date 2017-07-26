#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	if (n < 0) n = -n;
	int teklik = n % 10;
	int yuzluk = n / 100 % 10;
	int onminlik = n / 10000;
	cout << teklik*yuzluk*onminlik;
	return 0;
}
