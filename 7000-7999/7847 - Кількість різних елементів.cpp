#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> a;
	int n, x; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a.insert(x);
	}
	cout << a.size();
	return 0;
}
