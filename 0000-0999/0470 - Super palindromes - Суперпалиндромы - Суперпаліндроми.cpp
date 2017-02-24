#include <iostream>
#include <string.h>

using namespace std;

#define MAX 1001
char s[MAX];
int i, j, n, k, len, dp[MAX][MAX], pal[MAX][MAX];

//Реализуем рекурсивную функцию IsPal(i, j), которая возвращает 1, если si … sj является палиндромом.
//Иначе функция возвращает 0. Подстрока si…sj есть палиндром, если si = sj и si + 1 … sj - 1 является палиндромом.
//Значения IsPal(i, j) запоминаем в ячейках pal[i][j].
int IsPal(int i, int j)
{
	if (i >= j) return pal[i][j] = 1;
	if (pal[i][j] != -1) return pal[i][j];
	return pal[i][j] = s[i] == s[j] && IsPal(i + 1, j - 1);
}

int main() {
	gets(s); n = strlen(s);
	memset(dp, 0, sizeof dp);
	memset(pal, -1, sizeof pal);

	//Переберем все пары(i, i + len) по возрастанию длин интервалов.
	for (len = 1; len < n; len++)
		for (i = 0; i + len < n; i++)
		{
			j = i + len;
			//Подстрока si … sj содержит более одного символа.Если она палиндром, то она и суперпалиндром.
			if (IsPal(i, j))
			{
				dp[i][j] = 1;
				continue;
			}
			//Если si … sk и sk + 1 … sj суперпалиндромы, то si … sj является суперпалиндромом.
			for (k = i + 1; k < j - 1; k++)
				if (dp[i][k] && dp[k + 1][j])
				{
					dp[i][j] = 1;
					break;
				}
		}

	//Подсчитываем количество пар суперпалиндромов.
	int res = 0;
	for (i = 0; i < n; i++)
		for (j = 1; j < n; j++) res += dp[i][j];
	printf("%d\n", res);
	return 0;
}
