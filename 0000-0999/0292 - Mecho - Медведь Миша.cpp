#include <iostream>
#include <string.h>
#include <map>

using namespace std;

#define MAX 801
char m[MAX][MAX];

//Массив bees хранит время распространения пчел : bees[i][j] хранит наименьшее время, через которое пчелы будут в точке(i, j).
//Если пчелы не могут попасть в точку(i, j), то положим bees[i][j] = µ. Массивы DequeX и DequeY используем для поиска в ширину.
//Массив mecho используется для моделирования движения медведя(mecho[i][j] содержит
//наименьшее время, за которое медведь успеет добежать от горшочка с медом в точку(i, j)).

int DequeX[MAX*MAX], DequeY[MAX*MAX];
int bees[MAX][MAX], mecho[MAX][MAX];
int n, s, len, Left, Right, Mid;
int POS_beginX, POS_beginY, POS_endX, POS_endY;
bool flag;

//Добавляем пчелу в точку(i, j), прилетевшую сюда во время time. Если координаты(i, j) выходят за границы леса,
//или точке(i, j) соответствует не трава, или в точку(i, j) пчелы прилетели раньше(bees[i][j] ≤ time), то
//выходим из функции. Иначе добавляем координаты точки(i, j) в очередь (DequeX[len], DequeY[len]) и
//устанавливаем значение bees[i][j] равным time.

void AddBee(int i, int j, int time)
{
	if (i < 0 || j < 0 || i >= n || j >= n) return;
	if (m[i][j] != 'G' || bees[i][j] <= time) return;
	DequeX[len] = i; DequeY[len++] = j;
	bees[i][j] = time;
}

//Моделируем распространение пчел поиском в ширину.
//Пчелы перелетают из одной клетки в соседнюю за время s.
//Изначально пчелы находятся только в ульях.
void FillBees()
{
	int i, j, k, time;
	for (k = 0; k < len; k++)
	{
		i = DequeX[k]; j = DequeY[k]; time = bees[i][j] + s;
		AddBee(i - 1, j, time); AddBee(i + 1, j, time);
		AddBee(i, j - 1, time); AddBee(i, j + 1, time);
	}
}

//В момент времени time медведь заходит в точку(i, j). Он может войти в нее, если:
//·        она находится в пределах леса;
//·        в этой точке находится трава(дом Миши мы объявили “травой”);
//·        в этой точке нет пчел(bees[i][j] > time);
//·        Миша еще не был раньше в этой точке(mecho[i][j] содержит наименьшее время, за которое медведь сможет добраться до нее);
//Устанавливаем flag = 1, если в какой - то момент времени Миша достиг дома, имеющего координаты(POS_endX, POS_endY).
//В таком случае поиск останавливаем и возвращаемся из функции AddMecho.
void AddMecho(int i, int j, int time)
{
	if (flag) return;
	if (i < 0 || j < 0 || i >= n || j >= n) return;
	if (m[i][j] != 'G' || bees[i][j] <= time || mecho[i][j] <= time) return;
	DequeX[len] = i;
	DequeY[len++] = j;
	mecho[i][j] = time;
	if (i == POS_endX && j == POS_endY) flag = 1;
}

//Моделируем движение медведя поиском в ширину, используя очередь.
void RunMecho(void)
{
	int i, j, k, time;
	for (k = 0; k < len; k++)
	{
		i = DequeX[k]; j = DequeY[k]; time = mecho[i][j] + 1;
		AddMecho(i - 1, j, time); AddMecho(i + 1, j, time);
		AddMecho(i, j - 1, time); AddMecho(i, j + 1, time);
		if (flag) return;
	}
}

int main() {
	//Карту леса читаем в символьный массив m.
	memset(bees, 0x3F, sizeof bees);
	scanf("%d %d\n", &n, &s);
	for (int i = 0; i < n; i++) cin >> m[i];

	//Просматриваем посимвольно карту леса. Ищем начальное положение медведя(POS_beginX, POS_beginY),
	//координаты дома медведя(POS_endX, POS_endY), а также расположение ульев с пчелами.
	//Поскольку пчелы не могут залететь в дом Миши, отметим его на карте как “дерево”.
	//Начальное положение Миши объявим как “трава”(на него могут залететь пчелы).
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (m[i][j] == 'M')
			{
				POS_beginX = i; POS_beginY = j;
				m[i][j] = 'G';
			}
			else
				if (m[i][j] == 'D')
				{
					POS_endX = i; POS_endY = j;
					m[i][j] = 'T';
				}
				else if (m[i][j] == 'H') m[i][j] = 'G', AddBee(i, j, 0);
		}

	//Заполняем массив bees времени распространения пчел по лесу.
	FillBees();

	//Дом медведя теперь меняем с состояния “дерево” на “трава”, чтобы
	//медведь смог в него попасть(в клетку с деревом медведь зайти не может).
	m[POS_endX][POS_endY] = 'G';

	//Ищем максимально возможное количество минут на промежутке[Left; Right], на протяжении которых Миша
	//может продолжать есть мед в начальном расположении, имея возможность безопасно вернуться домой.
	//Для этого используем бинарный поиск.
	Left = -1; Right = bees[POS_beginX][POS_beginY] / s + 1;
	while (Left < Right)
	{
		Mid = (Left + Right + 1) / 2;

		//Для значения Mid следует определить, сможет ли медведь есть мед в точности Mid минут, после чего безопасно вернуться домой.
		memset(mecho, 0x3F, sizeof mecho);

		//Медведь начинает движение из точки(POS_beginX, POS_beginY) в момент времени Mid * s(через s минут после сигнала тревоги).
		flag = len = 0; AddMecho(POS_beginX, POS_beginY, Mid*s);
		RunMecho();

		//Отметим, что mecho[i][j] = µ, если медведь не сможет добраться до точки(i, j)
		//(или его в этой точке ужалят пчелы, или там находится дерево).
		if (mecho[POS_endX][POS_endY] == 0x3F3F3F3F) Right = Mid - 1;
		else Left = Mid;
	}
	printf("%d\n", Left);
	return 0;
}
