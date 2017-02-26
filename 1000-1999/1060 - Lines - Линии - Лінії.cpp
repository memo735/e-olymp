#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 50
int i, j, n, mas[MAX][MAX];
char ch, s[256];

class Cell
{
public:
	int x, y;
	Cell(int x = 0, int y = 0) : x(x), y(y) {}
};
Cell start, finish;
queue<Cell> q;

//Функция CanGo возвращает 1, если можно пойти в точку с координатами(i, j).
int CanGo(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= n) return 0;
	if (mas[i][j] != -1) return 0;
	return 1; // can go
}

//Поиск в ширину из точки Start.
void bfs(Cell Start)
{
	int i = Start.x, j = Start.y;
	int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	q.push(Start);
	mas[i][j] = 0;
	while (!q.empty())
	{
		i = q.front().x; j = q.front().y; q.pop();
		if (i == finish.x && j == finish.y) return; // destination reached
		for (int k = 0; k < 4; k++)
		{
			int ii = i + dx[k]; // (i, j) -> (ii, jj)
			int jj = j + dy[k];
			if (CanGo(ii, jj))
			{
				q.push(Cell(ii, jj));
				mas[ii][jj] = mas[i][j] + 1;
			}
		}
	}
}

int main() {
	//В переменные start и finish заносим начальную и конечную позицию. Заполняем массив mas.
	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%c", &ch);
			mas[i][j] = -1;
			if (ch == '@') start = Cell(i, j);
			if (ch == 'X') finish = Cell(i, j);
			else if (ch == 'O') mas[i][j] = -2; // forbidden to move
		}
		gets(s);
	}
	//Запускаем поиск в ширину.
	bfs(start);
	//Если конечная точка не достижима, то выводим N.
	if (mas[finish.x][finish.y] == -1)
	{
		printf("N\n");
		return 0;
	}
	//Иначе заполняем кратчайший путь плюсами.
	printf("Y\n");
	i = finish.x;
	j = finish.y;
	int cnt = mas[finish.x][finish.y];
	for (int k = 0; k < cnt; k++)
	{
		int ii = i, jj = j;
		if (i > 0 && mas[i - 1][j] == mas[i][j] - 1) i--;
		else
			if (i < n - 1 && mas[i + 1][j] == mas[i][j] - 1) i++;
			else
				if (j > 0 && mas[i][j - 1] == mas[i][j] - 1) j--;
				else
					if (j < n && mas[i][j + 1] == mas[i][j] - 1) j++;
		mas[ii][jj] = -3; // +   
	}
	//Выводим результирующую доску.
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			char c = '.';
			if (mas[i][j] == -2) c = 'O';
			if (mas[i][j] == 0) c = '@';
			if (mas[i][j] == -3) c = '+';
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
