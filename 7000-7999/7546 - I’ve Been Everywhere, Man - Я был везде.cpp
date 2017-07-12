#include <iostream>
#include <set>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t-- > 0)
	{
		int n; cin >> n;
		char x[30];
		set<string> a;
		while (n-- > 0)
		{
			cin >> x;
			a.insert(x);
		}
		cout << a.size() << endl;
	}
	return 0;
}
