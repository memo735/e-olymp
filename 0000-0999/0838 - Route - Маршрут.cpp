#include <iostream>
#include <algorithm>

using namespace std;


int mas[250][250], n, m, x, y;
char tmp;

int main()
{
	cin >> n;
	m = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			mas[i][j] = tmp - 48;
		}
	}
	for (int i = 1; i < n; i++) mas[i][0] += mas[i - 1][0];
	for (int j = 1; j < m; j++) mas[0][j] += mas[0][j - 1];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) mas[i][j] += min(mas[i - 1][j], mas[i][j - 1]);
	x = n - 1; y = m - 1;
	while (x != 0 || y != 0)
	{
		mas[x][y] = -1;
		if (x > 0 && y > 0)
		{
			if (mas[x - 1][y] < mas[x][y - 1]) x--;
			else y--;
		}
		else if (x == 0) y--;
		else if (y == 0) x--;
	}
	mas[0][0] = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] == -1) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
}
