#include <iostream>

using namespace std;

#define SIZE 100

long long mas[SIZE][SIZE], n, m, x, y;

char tmp;

int main()
{
	cin >> n >> m;
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++) cin >> mas[i][j];
	}

	for (int i = 1; i < n; i++) mas[i][0] += mas[i - 1][0];
	for (int j = 1; j < m; j++) mas[0][j] += mas[0][j - 1];

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) mas[i][j] += max(mas[i - 1][j], mas[i][j - 1]);

	x = n - 1; y = m - 1;
	while (x != 0 || y != 0)
	{
		mas[x][y] = -1;
		if (x > 0 && y > 0)
		{
			if (mas[x - 1][y] > mas[x][y - 1]) x--;
			else y--;
		}
		else if (x == 0) y--;
		else if (y == 0) x--;
	}
	mas[0][0] = -1;
	x = y = 0;
	while (x != n-1 || y != m-1)
	{
		if (x < n - 1 && mas[x + 1][y] == -1) { cout << "F"; x++; }
		else { cout << "R"; y++; }
	}
	cout << endl;
}
