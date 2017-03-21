#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 100

bool mas[SIZE][SIZE];
int n, m, tmp, answer = 0, x, y, k;

void rec(int a, int b)
{
	mas[a][b] = false;
	tmp++;
	if (a > 0 && mas[a - 1][b]) rec(a - 1, b);
	if (a < n - 1 && mas[a + 1][b]) rec(a + 1, b);
	if (b > 0 && mas[a][b - 1]) rec(a, b - 1);
	if (b < m - 1 && mas[a][b + 1]) rec(a, b + 1);
}

int main()
{
	cin >> n >> m >> k;
	memset(mas, false, SIZE*SIZE);
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		mas[x - 1][y - 1] = true;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp = 0;
			if (mas[i][j]) rec(i, j);
			if (tmp > answer) answer = tmp;
		}
	}
	cout << answer << endl;
	return 0;
}
