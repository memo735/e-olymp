#include <iostream>

using namespace std;

int main(){
	int x0, y0, R, x, y;
	cin >> x0 >> y0 >> R;
	cin >> x >> y;
	cout << ((x - x0)*(x - x0) + (y - y0)*(y - y0) <= R*R ? "YES" : "NO");
	return 0;
}
