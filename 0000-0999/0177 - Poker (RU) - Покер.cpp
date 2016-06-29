#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector <int> vect;
vector <string> vstr, answer;

int n;
string str;
bool push;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vect.clear(); vstr.clear();
		for (int j = 0; j < 5; j++)
		{
			push = false;
			cin >> str;
			for (int h = 0; h < vstr.size(); h++)
				if (vstr[h] == str) { push = true; vect[h]++; }
			if (!push) { vect.push_back(1); vstr.push_back(str); }
		}
		sort(vect.begin(), vect.end());
		if (vect[vect.size() - 1] == 5) answer.push_back("poker");
		else if (vect[vect.size() - 1] == 4) answer.push_back("quads");
		else if (vect[vect.size() - 1] == 3 && vect[vect.size() - 2] == 2) answer.push_back("full house");
		else if (vect[vect.size() - 1] == 3) answer.push_back("set");
		else if (vect[vect.size() - 1] == 2 && vect[vect.size() - 2] == 2)answer.push_back("two pair");
		else if (vect[vect.size() - 1] == 2)answer.push_back("pair");
		else answer.push_back("no pair");
	}
	for (int i = 0; i < n; i++) cout << answer[i] << endl;
}
