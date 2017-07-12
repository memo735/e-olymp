#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char str[1001]; cin >> str;
	string ans;
	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		ans += c;
		if (c == '-')
		{
			ans += str[++i];
			while (i + 1 < strlen(str) && str[i + 1] == '0')
			{
				ans += '+';
				ans += str[++i];
			}
			if (i + 1 < strlen(str) && '1' <= str[i + 1] && str[i + 1] <= '9')
			{
				ans += '+';
			}
		}
	}
	printf("%s", ans.c_str());
	return 0;
}
