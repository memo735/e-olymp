#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long n, m, k, i;
	vector<long> v;
	cin >> k >> n >> m;
	for (i = 1; i*i < n; i++)
	{
		if (n % i == 0)
		{
			if (m % (i + k) == 0) v.push_back(i);
			if (m % (n / i + k) == 0) v.push_back(n / i);
		}
	}
	if (i*i == n && m % (i + k) == 0) v.push_back(i);
	sort(v.begin(), v.end());
	for(i = 0; i < v.size(); i++) cout << v[i] << endl;
}
