#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
	char s[100];
	int i, n;
	while (scanf("%d %s", &n, s), n)
	{
		int len = strlen(s);
		reverse(s, s + len);
		for (i = 0; i < len; i++)
		{
			if (s[i] == '.') s[i] = 27;
			else s[i] == '_' ? s[i] = 26 : s[i] -= 'A';
			s[i] = (s[i] + n) % 28;
			if (s[i] == 27) s[i] = '.';
			else s[i] == 26 ? s[i] = '_' : s[i] += 'A';
		}
		puts(s);
	}
	return 0;
}
