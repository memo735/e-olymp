#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f(int a, int b)
{
	return a > b;
}

int main()
{
	int n, t, i;
	vector<int> v;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end(), f);
	if (v.size() > 0)
	{
		cout << v[0];
		for (i = 1; i < v.size(); i++) cout << " " << v[i];
	}
	cout << endl;
}
