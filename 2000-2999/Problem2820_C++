#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <pair<int, pair<int, int>>> vect;
pair <int, int> a, b;
pair <string, string> str;
bool check[8][8];
int index, X, Y;

inline void add(int xtmp, int ytmp, int value)
{
	if (xtmp >= 0 && xtmp < 8 && ytmp >= 0 && ytmp < 8)
	{
		if (check[xtmp][ytmp] == false)
		{
			vect.push_back(make_pair(value, make_pair(xtmp, ytmp)));
			check[xtmp][ytmp] = true;
		}
	}
}

int main()
{
	while (cin)
	{
		str.first.clear();
		str.second.clear();
		cin >> str.first >> str.second;
		if (str.first.length() == 2 && str.second.length() == 2)
			if (cin)
			{
				a.first = str.first[0] - 97;
				a.second = str.first[1] - 49;
				b.first = str.second[0] - 97;
				b.second = str.second[1] - 49;
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++) check[i][j] = false;

				vect.clear();
				vect.push_back(make_pair(0, make_pair(a.first, a.second)));
				index = 0;
				check[a.first][a.second] = true;
				while (vect[index].second != b)
				{
					X = vect[index].second.first;
					Y = vect[index].second.second;
					add(X + 1, Y + 2, vect[index].first + 1);
					add(X + 2, Y + 1, vect[index].first + 1);
					add(X - 1, Y + 2, vect[index].first + 1);
					add(X - 2, Y + 1, vect[index].first + 1);
					add(X + 1, Y - 2, vect[index].first + 1);
					add(X + 2, Y - 1, vect[index].first + 1);
					add(X - 1, Y - 2, vect[index].first + 1);
					add(X - 2, Y - 1, vect[index].first + 1);
					index++;
				}
				cout << "To get from " << str.first << " to " << str.second << " takes " << vect[index].first << " knight moves.\n";
			}
	}
}
