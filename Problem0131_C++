#include <iostream>
#include <string>
#include <vector>

using namespace std;
string tmpstr;
vector <pair<char, int>> vect, tmpvect;
int n, answer;

void str_processing(vector < pair < char, int >> &v)
{
	bool find = false;
	for (int j = 0; j < tmpstr.length(); j++)
	{
		find = false;
		for (int g = 0; g < v.size(); g++)
		{
			if (v[g].first == tmpstr[j])
			{
				find = true;
				v[g].second++;
			}
		}
		if (!find) v.push_back(make_pair(tmpstr[j], 1));
	}
}

bool calculate()
{
	bool ok;
	for (int j = 0; j < tmpvect.size(); j++)
	{
		ok = false;
		for (int g = 0; g < vect.size(); g++)
		{
			if (vect[g].first == tmpvect[j].first && vect[g].second >= tmpvect[j].second) ok = true;
		}
		if (!ok) return false;
	}
	return true;
}

int main()
{
	cin >> tmpstr;
	str_processing(vect);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		tmpvect.clear();
		cin >> tmpstr;
		str_processing(tmpvect);
		if (calculate()) answer++;
	}
	cout << answer << endl;
}
