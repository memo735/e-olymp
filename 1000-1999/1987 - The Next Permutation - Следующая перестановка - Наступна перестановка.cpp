#include <iostream>
#include <string>

using namespace std;

int n, tmp, a, b;
string s;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> tmp >> s;
		cout << tmp << " ";
		a = -1;
		for (int i = s.length() - 1; i >= 0; i--)
			if (s[i] < s[i + 1])
			{
				a = i;
				i = -1;
			}
		if (a == -1) cout << "BIGGEST" << endl;
		else
		{
			b = a + 1;
			for (int i = a + 2; i < s.length(); i++)
			{
				if (s[i] < s[b] && s[i] > s[a]) b = i;
			}
			swap(s[a], s[b]);
			for (int x = a + 1; x < s.length() - 1; x++)
				for (int y = x + 1; y < s.length(); y++)
					if (s[x] > s[y]) swap(s[x], s[y]);

			cout << s << endl;
		}
	}
	return 0;
}
