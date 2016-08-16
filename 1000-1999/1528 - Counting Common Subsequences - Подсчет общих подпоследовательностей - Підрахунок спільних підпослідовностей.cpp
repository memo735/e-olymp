#include <iostream>
#include <string.h>

using namespace std;

long f[51][51][51], res;
char s1[100], s2[100], s3[100];

//Функция countCommonSubsequences вычисляет количество разных непустых общих подпоследовательностей в строках a, b, c.
long countCommonSubsequences(string a, string b, string c)
{
	int i, j, k, x, y, z;
	f[0][0][0] = 1; res = 0;
	for (i = 0; i <= a.size(); i++)
		for (j = 0; j <= b.size(); j++)
			for (k = 0; k <= c.size(); k++)
				if (f[i][j][k] > 0)
				{
					for (char ch = 'a'; ch <= 'z';ch++)
					{
						x = a.find(ch, i); y = b.find(ch, j); z = c.find(ch, k);
						if (x != string::npos && y != string::npos && z != string::npos)
							f[x + 1][y + 1][z + 1] += f[i][j][k];
					}
					res += f[i][j][k];
				}
	return res - 1;
}

int main() {
	while (gets(s1))
	{
		gets(s2);
		gets(s3);
		memset(f, 0, sizeof f);
		printf("%ld\n", countCommonSubsequences(s1, s2, s3));
	}
	return 0;
}
