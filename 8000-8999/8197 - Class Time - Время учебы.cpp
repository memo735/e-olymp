#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
pair<string, string> a[128];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(&a[0], &a[n]);
	for (int i = 0; i < n; i++) cout << a[i].second << " " << a[i].first << endl;
	return 0;
}
