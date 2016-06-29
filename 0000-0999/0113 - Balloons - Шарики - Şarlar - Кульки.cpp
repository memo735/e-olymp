#include <iostream>
#include <vector>

using namespace std;

vector <pair<int, int>> vect;
int n, tmp, MAX = 1;
bool push = false;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		push = false;
		for (int j = 0; j < vect.size(); j++)
			if (vect[j].first == tmp)
			{
				if (MAX == vect[j].second) MAX++;
				vect[j].second++;
				push = true;
			}
		if (!push) vect.push_back(make_pair(tmp, 1));
	}
	cout << n - MAX << endl;
}
