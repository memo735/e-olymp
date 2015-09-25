#include <iostream>
#include <vector>

using namespace std;

vector <pair<long long, long long>> vect;
long long n, answer = 0, tmp;
bool push;

int main()
{
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> tmp;
		push = false;
		for (int j = 0; j < vect.size(); j++)
		{
			if (vect[j].first == tmp)
			{
				push = true;
				vect[j].second++;
			}
		}
		if (!push) vect.push_back(make_pair(tmp, 1));
	}
	for (int i = 0; i < vect.size(); i++) answer += vect[i].second / 4;
	cout << answer << endl;
}
