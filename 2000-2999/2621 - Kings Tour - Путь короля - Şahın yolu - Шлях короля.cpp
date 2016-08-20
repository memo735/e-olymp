#include <iostream>
#include <string.h>
#include <deque>

using namespace std;

int m[10][10];
char kx, ky, pax, pay, pbx, pby;
deque<pair<int, int>> d;
int xx[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int yy[8] = { -1, 0, 1, -1, 0, 1, 1, -1 };

//Функция cango проверяет, не находится ли поле (x, y) за границами шахматной доски.
int cango(int x, int y)
{
	if (x < 1 || x > 8 || y < 1 || y > 8 || m[x][y] >= 0) return 0;
	return 1;
}

//Запускаем поиск в ширину из клетки(x, y).С его помощью ищем кратчайший путь короля до каждой из пешек.
void bfs(int x, int y)
{
	pair<int, int> temp;
	m[x][y] = 0;
	d.push_back(make_pair(x, y));
	while (!d.empty())
	{
		temp = d[0]; d.pop_front();

		//Перебираем все возможные ходы короля.
		for (int i = 0; i < 8; i++)
			if (cango(temp.first + xx[i], temp.second + yy[i]))
			{
				m[temp.first + xx[i]][temp.second + yy[i]] = m[temp.first][temp.second] + 1;
				d.push_back(make_pair(temp.first + xx[i], temp.second + yy[i]));
			}
	}
}

//Функция attackPawns возвращает наименьшее количество ходов, за которое король сможет побить пешку A.
int attackPawns()
{
	int a, b;
	memset(m, -1, sizeof m);

	//В поля, находящиеся под ударом пешек, поставим значения 1000. Это
	//делается для того, чтобы при поиске в ширину король в них не зашел.
	m[pax - 1][pay + 1] = m[pax + 1][pay + 1] = 1000;
	m[pbx - 1][pby + 1] = m[pbx + 1][pby + 1] = 1000;
	bfs(kx, ky);

	//До пешки А король может добраться минимум за а ходов, а до пешки B за b ходов.
	a = m[pax][pay]; b = m[pbx][pby];
	memset(m, -1, sizeof m);
	m[pax - 1][pay + 1] = m[pax + 1][pay + 1] = 1000;

	//Вычисляем кратчайший путь от пешки В до пешки А.
	bfs(pbx, pby); b += m[pax][pay];

	//В переменной a содержится длина кратчайшего пути короля до пешки A без сбивания
	//пешки В, а в переменной b с ее сбиванием.Возвращаем меньшее значение среди a и b.
	return a < b ? a : b;
}

int main() {
	//Читаем входные данные.Находим и выводим ответ.
	while (scanf("%c%c %c%c %c%c\n", &kx, &ky, &pax, &pay, &pbx, &pby) == 6)
	{
		kx -= 'a' - 1; ky -= '1' - 1;
		pax -= 'a' - 1; pay -= '1' - 1;
		pbx -= 'a' - 1; pby -= '1' - 1;
		printf("%d\n", attackPawns());
	}
	return 0;
}
