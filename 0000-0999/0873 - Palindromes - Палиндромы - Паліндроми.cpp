#include <iostream>
#include <string.h>

using namespace std;

#define MAX 55
char s[MAX];
long i, j, n, len, dp[MAX][MAX];

int main() {
	gets(s); n = strlen(s);
	memset(dp, 0, sizeof dp);
	for (i = 0; i < n; i++) dp[i][i] = 1;
	//Перебираем длины подстрок len и позиции их начала i.
	for (len = 1; len < n; len++)
		for (i = 0; i + len < n; i++)
		{
			j = i + len;
			//Для каждой такой подстроки si … sj вычисляем значение dp[i][j] – количество палиндромов,
			//которое можно получить из нее удалением символов. Поскольку подстроки si … sj перебираются
			//в порядке возрастания их длин, то значения dp на всех подотрезках меньшей длины уже вычислены.
			if (s[i] == s[j]) dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
			else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
		}
	printf("%ld\n", dp[0][n - 1]);
	return 0;
}
