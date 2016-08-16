#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int d, k, s[1001], dp[1001][1001];
char stroka[1001];

//Функция maximalGoodness возвращает наибольшую возможную сумму характеристик.
int maximalGoodness(int d, int k)
{
	int i, j, temp, len = strlen(stroka);
	
	//Вычислим сумму характеристик всех моментов времени от 1 до i - го и занесем ее в s[i].
	memset(s, 0, sizeof s);
	for (i = 1; i <= len; i++) s[i] = s[i - 1] + stroka[i - 1] - 'a' + 1;
	memset(dp, 0, sizeof dp);
	for (i = 1; i <= len; i++)
		for (j = 1; j <= k; j++)
		{
			if (i - d < 0) temp = 0;
			else temp = i - d;
			dp[i][j] = max(dp[i - 1][j], dp[temp][j - 1] + s[i] - s[temp]);
		}
	return dp[len][k];
}

int main() {
	while (scanf("%d %d\n", &d, &k) == 2)
	{
		gets(stroka);
		printf("%d\n", maximalGoodness(d, k));
	}
	return 0;
}
