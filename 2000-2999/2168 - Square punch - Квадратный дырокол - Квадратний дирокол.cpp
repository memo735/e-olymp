#include <iostream>

using namespace std;

int n, m, Sum = 0, mas[100][100];

void rec(int x, int y)
{
	mas[x][y] = 1;
	if (x > 0 && mas[x - 1][y] == 0) rec(x - 1, y);
	if (y > 0 && mas[x][y - 1] == 0) rec(x, y - 1);
	if (x < n - 1 && mas[x + 1][y] == 0) rec(x + 1, y);
	if (y < m - 1 && mas[x][y + 1] == 0) rec(x, y + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> mas[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (mas[i][j] == 0)
			{
				rec(i, j);
				Sum++;
			}
	}
	cout << Sum << endl;
}
