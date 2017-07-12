#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
	char s[9]; cin >> s;
	int n; cin >> n;
	string ans[1001];
	int ac = 0;
	for (int i = 0; i < n; i++)
	{
		char t[1001]; cin >> t;
		if (strlen(s) != strlen(t)) continue;
		bool ok = true;
		for (int j = 0; j < strlen(s); j++)
		{
			if (s[j] == '*') continue;
			if (s[j] != t[j])
			{
				ok = false;
				break;
			}
		}
		if (ok) ans[ac++] = t;
	}
	cout << ac << endl;
	for (int i = 0; i < ac; i++) printf("%s\n", ans[i].c_str());
}
