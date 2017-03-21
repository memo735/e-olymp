#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <int> vect;
pair <int, int> MinMax;

int main()
{
	cin >> n;
	vect.reserve(n);
	cin >> vect[0];
	MinMax.first = MinMax.second = vect[0];
	for (int i = 1; i < n; i++)
	{
		cin >> vect[i];
		MinMax.first = min(MinMax.first, vect[i]);
		MinMax.second = max(MinMax.second, vect[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (vect[i] == MinMax.second) vect[i] = MinMax.first;
		cout << vect[i] << (i < n - 1 ? " " : "\n");
	}
	return 0;
}
