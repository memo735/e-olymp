#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 50
#define INF 0x3F3F3F3F
#define SubINF 2600

//Массив used и очередь q будут использоваться при поиске кратчайших расстояний от машин до парковок.
//Массив m содержит матрицу смежности графа, на которой будет запускаться поток. dist[i][j] содержит
//кратчайшее расстояние от i-ой машины до j-го парковочного места. Координаты парковок храним в массиве Parks.
//Начальное состояние парковки считываем в массив строк park.
deque<pair<int, int>> q;
int i, L, R, V, Mid, res, row, Cars, column, ParkingLot, used[MAX][MAX], m[202][202], usedFlow[202];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
char s[101];
vector<vector<int>> dist;
vector<pair<int, int>> Parks;
vector<string> park;


//Запускаем поиск в ширину на парковке, начиная с точки(x, y). По завершению работы
//процедуры bfs ячейка used[i][j] будет содержать кратчайшее расстояние от (x, y) до (i, j).
void bfs(int x, int y)
{
	q.push_back(make_pair(x, y));
	used[x][y] = 0;
	while (!q.empty())
	{
		int xx = q[0].first, yy = q[0].second;
		q.pop_front();

		//Из точки (x, y) машина может за единицу времени переместиться в(x + dx[i], y + dy[i]), 1 ≤ i ≤ 4.
		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i], ny = yy + dy[i];

			//Проверяем, чтобы координаты нового положения машины (nx, ny) не выходили за границы. Если в
			//точке (nx, ny) мы уже побывали (и кратчайшее расстояние от (x, y) до нее уже вычислено в
			//массиве used), либо если в точке(nx, ny) находится стена, то далее эту позицию не обрабатываем.
			if (nx < 0 || nx >= row || ny < 0 || ny >= column) continue;
			if (used[nx][ny] != -1 || park[nx][ny] == 'X') continue;
			used[nx][ny] = used[xx][yy] + 1;
			q.push_back(make_pair(nx, ny));
		}
	}
}

//Следующие две функции используются для нахождения максимального
//потока. Матрица пропускных способностей находится в массиве m.
int aug(int x, int t, int CurFlow)
{
	if (x == t) return CurFlow;
	if (usedFlow[x]++) return 0;
	for (int Flow, y = 0; y <= V; y++)
	{
		if (m[x][y] > 0 && (Flow = aug(y, t, min(CurFlow, m[x][y]))))
		{
			m[x][y] -= Flow;
			m[y][x] += Flow;
			return Flow;
		}
	}
	return 0;
}

//Функция FindFlow возвращает величину максимального потока
//между истоком 0 и стоком V = Cars + ParkingLot + 1.
int FindFlow()
{
	int flow, MaxFlow = 0;
	do
	{
		memset(usedFlow, 0, sizeof usedFlow);
	} while ((flow = aug(0, V, 0x7FFFFFFF)) && (MaxFlow += flow));
	return MaxFlow;
}

//Функция CanSolve возвращает 1, если машины могут разъехаться по парковкам за время Mid.
//Это возможно, если только величина потока будет равняться количеству машин Cars.
//Пронумеруем вершины двудольного графа следующим образом :
//·        вершина 0 – исток,
//·        вершины 1 ..Cars – левая доля, соответствуют машинам,
//·        вершины Cars + 1 ..Cars + ParkingLot – правая доля, соответствуют парковкам,
//·        Cars + ParkingLot + 1 – сток
//Ребра графа с пропускной способностью 1 строятся следующим образом :
//·        от истока до каждой машины
//·        от каждой парковки до стока
//·        от машины i до парковки j, если только i - ая машина сможет доехать до до парковки j за время, не большее Mid.
int CanSolve(int Mid)
{
	int i, j;
	memset(m, 0, sizeof m);
	for (i = 1; i <= Cars; i++) m[0][i] = 1;
	for (i = 1; i <= ParkingLot; i++) m[Cars + i][V] = 1;
	for (i = 0; i < Cars; i++)
		for (j = 0; j < ParkingLot; j++)
			if (dist[i][j] <= Mid) m[i + 1][Cars + j + 1] = 1;

	return FindFlow() == Cars;
}

//Функция minTime возвращает наименьшее время, за которое машины смогут
//разъехаться по парковкам. Если это невозможно, функция возвращает - 1.
int minTime()
{
	int i, j, k;
	Parks.clear();
	dist.clear();

	//Определяем координаты парковок и заносим их в масив пар Parks.
	for (i = 0; i < row; i++)
		for (j = 0; j < column; j++)
			if (park[i][j] == 'P') Parks.push_back(make_pair(i, j));

	Cars = 0; ParkingLot = Parks.size();
	//Перебираем все позиции парковки (i, j). Если на клетке (i, j) находится машина, то
	//запускаем с нее поиск в ширину. Таким образом находим кратчайшие расстояния от нее
	//до всех парковок. Составляем матрицу кратчайших расстояний dist между машинами и
	//парковками : dist[i][j] содержит кратчайшее расстояние от i - ой машины до j - ой парковки.
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++)
		{
			if (park[i][j] == 'C')
			{
				memset(used, -1, sizeof used);
				bfs(i, j);
				Cars++;
				vector<int> c(ParkingLot);
				for (k = 0; k < ParkingLot; k++)
				{
					c[k] = used[Parks[k].first][Parks[k].second];
					if (c[k] == -1) c[k] = INF;
				}
				//Массив c содержит кратчайшие расстояния от i-ой машины до всех парковок.
				//Если машина не может добраться до k - ой парковки, то полагаем c[k] = INF.
				dist.push_back(c);
			}
		}
	}
	//Если количество машин превышает количество стоянок, то вернуть - 1.
	if (Cars > ParkingLot) return -1;
	V = Cars + ParkingLot + 1;

	//При помощи бинарного поиска по времени ищем наименьшее время, за которое машины разъедутся по парковкам.
	//Искомое время является целочисленным и находится в промежутке [L..R]. Поскольку размер парковки максимум
	//50 * 50, то с учетом стен наибольшее расстояние между машиной и парковкой должно быть не больше
	L = 0; R = SubINF;
	while (L < R)
	{
		Mid = (L + R) / 2;
		if (CanSolve(Mid)) R = Mid; else L = Mid + 1;
	}
	return L;
}

int main() {
	while (scanf("%d %d\n", &row, &column) == 2)
	{
		park.clear();
		for (i = 0; i < row; i++)
		{
			gets(s);
			park.push_back((string)s);
		}
		//Вычисляем искомое минимальное время res. Если машины не могут разъехаться за время 0,
		//то они не могут разъехаться вообще.Если машинам не достаточно SubINF времени, то они
		//также разъехаться не могут. Если количество машин на парковке равно нулю, то полагаем res = 0.
		res = minTime();
		if (!Cars) res = 0;
		else
			if (res == 0 || res == SubINF) res = -1;
		printf("%d\n", res);
	}
	return 0;
}
