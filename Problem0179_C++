#include <iostream>
#include <vector>

using namespace std;

vector <long long int > a;
long long int n, tmp, delta = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp; a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp; delta += abs(tmp - a[i]);
	}
	cout << delta / 2 << endl;
}
