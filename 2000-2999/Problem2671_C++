#include <iostream>

using namespace std;

int n, m, w, mas[32][32], x, y;

int main()
{
	cin >> n >> m >> w;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) mas[i][j] = 0;
	}
	for (int i = 0; i < w; i++)
	{
		cin >> x >> y;
		mas[x - 1][y - 1] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] == -1) cout << "*";
			else
			{
				if (i > 0 && mas[i - 1][j] == -1) mas[i][j]++;
				if (i < n - 1 && mas[i + 1][j] == -1) mas[i][j]++;
				if (j > 0 && mas[i][j - 1] == -1) mas[i][j]++;
				if (j < m - 1 && mas[i][j + 1] == -1) mas[i][j]++;
				if (i > 0 && j > 0 && mas[i - 1][j - 1] == -1) mas[i][j]++;
				if (i > 0 && j < m - 1 && mas[i - 1][j + 1] == -1) mas[i][j]++;
				if (i < n - 1 && j > 0 && mas[i + 1][j - 1] == -1) mas[i][j]++;
				if (i < n - 1 && j < m - 1 && mas[i + 1][j + 1] == -1) mas[i][j]++;
				cout << (char)(mas[i][j] + 48);
			}
			if (j < m - 1) cout << " ";
		}
		cout << endl;
	}
}
