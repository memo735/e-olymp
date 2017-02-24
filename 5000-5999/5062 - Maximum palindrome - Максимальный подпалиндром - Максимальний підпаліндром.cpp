#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 111
char x[MAX], y[MAX], res[MAX];
int i, j, len, ptr, m[MAX][MAX];

int main() {
	x[0] = y[0] = 0;
	gets(x + 1); strcpy(y + 1, x + 1);
	len = strlen(x + 1);
	reverse(y + 1, y + 1 + len);
	memset(m, 0, sizeof m);
	for (i = 1; i <= len; i++)
		for (j = 1; j <= len; j++)
			if (x[i] == y[j]) m[i][j] = 1 + m[i - 1][j - 1];
			else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
			i = j = len;
			while (m[i][j])
			{
				if (x[i] == y[j])
				{
					res[ptr++] = x[i];
					i--; j--;
				}
				else
					if (m[i - 1][j] > m[i][j - 1]) i--;
					else j--;
			}
			puts(res);
			return 0;
}
