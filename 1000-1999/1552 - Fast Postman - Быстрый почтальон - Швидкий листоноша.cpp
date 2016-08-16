#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define INF 2000000000

int i, res, Num, value, InitPos, sol[50][50][2];
vector<int> address, maxTime;

//Функция minTime возвращает наименьшее возможное время доставки всех писем при заданных ограничениях.
int minTime()
{
	int res, i, j, n = address.size();

	//Создаем массив пар houses, содержащий адреса и время доставки писем.Сортируем пары по адресам.
	vector<pair<int, int> > h;
	for (i = 0; i < n; i++) h.push_back(make_pair(address[i], maxTime[i]));
	sort(h.begin(), h.end());
	memset(sol, 0, sizeof sol);
	for (i = 0; i < n; i++)
	{
		sol[i][i][0] = sol[i][i][1] = abs(h[i].first - InitPos);
		if (sol[i][i][0] > h[i].second) sol[i][i][0] = sol[i][i][1] = INF;
	}
	//Заполняем ячейки массива sol.
	for (i = n - 1; i >= 0; i--) {
		for (j = i + 1; j < n; j++)
		{
			sol[i][j][0] = min(sol[i + 1][j][0] + h[i + 1].first - h[i].first, sol[i + 1][j][1] + h[j].first - h[i].first);
			if (sol[i][j][0] > h[i].second) sol[i][j][0] = INF;
			sol[i][j][1] = min(sol[i][j - 1][0] + h[j].first - h[i].first, sol[i][j - 1][1] + h[j].first - h[j - 1].first);
			if (sol[i][j][1] > h[j].second) sol[i][j][1] = INF;
		}
	}
	res = min(sol[0][n - 1][0], sol[0][n - 1][1]);
	if (res == INF) return -1;
	return res;
}

int main() {
	while (scanf("%d %d", &Num, &InitPos) == 2)
	{
		address.clear(); maxTime.clear();
		for (i = 0; i < Num; i++) scanf("%d", &value), address.push_back(value);
		for (i = 0; i < Num; i++) scanf("%d", &value), maxTime.push_back(value);
		res = minTime();
		printf("%d\n", res);
	}
	return 0;
}
