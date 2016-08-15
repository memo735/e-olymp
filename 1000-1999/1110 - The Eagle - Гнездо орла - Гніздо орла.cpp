#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 201

vector<pair<int, string> > v;
int i, j, k, n, t, flow, MaxFlow, m[MAX][MAX], used[MAX];
vector<int> g;
char s[20];

//Запускаем алгоритм вычисления наибольшей возрастающей подпоследовательности (НВП).
//По завершению функции LIS длина НВП содержится в переменной k.Для каждой миссии в
//массиве g запоминаем, на каком месте НВП она может находиться.
void LIS(vector<pair<int, string> > &v)
{
	int i, pos;
	vector<int> lis(v.size(), 0);
	g.resize(v.size());
	for (k = i = 0; i < v.size(); i++)
	{
		pos = lower_bound(lis.begin(), lis.begin() + k, v[i].first) - lis.begin();
		lis[pos] = v[i].first;
		if (pos == k) k++;

		//Миссия i в НВП может находиться на позиции pos.
		g[i] = pos;
	}
}

//Ищем максимальный поток в графе.
int aug(int x, int t, int CurFlow)
{
	if (x == t) return CurFlow;
	if (used[x]++) return 0;

	for (int Flow, y = 0; y <= 2 * n + 1; y++)
	{
		if (m[x][y] > 0 && (Flow = aug(y, t, min(CurFlow, m[x][y]))))
		{
			m[x][y] -= Flow; m[y][x] += Flow;
			return Flow;
		}
	}
	return 0;
}

int main() {
	//Читаем входные миссии и заносим их в массив v.
	scanf("%d\n", &n);
	v.clear(); g.clear();
	for (i = 0; i < n; i++)
	{
		scanf("%s %d\n", s, &t);
		v.push_back(make_pair(t, string(s)));
	}
	//Запускаем алгоритм построения НВП. Строим массив g.
	LIS(v);
	memset(m, 0, sizeof m);

	//Строим многоярусную сеть. Проводим ориентированное ребро между двумя вершинами одной миссии(от вершины 2i к 2i – 1).
	for (i = 1; i <= n; i++) m[2 * i][2 * i - 1] = 1;

	//Проведем ребра из вершин нулевого яруса в сток, которому соответствует вершина номер 2n + 1.
	//Если для i - ой миссии значение g[i – 1] равно нулю, то i - ая миссия находится на нулевом ярусе,
	//и от нее(вершины 2i – 1) следует провести ребро в сток.
	for (i = 1; i <= g.size(); i++)
		if (g[i - 1] == 0) m[2 * i - 1][2 * n + 1] = 1;

	//Проведем ребра из истока 0 в вершины(k – 1) - го яруса.
	for (i = 1; i <= g.size(); i++)
		if (g[i - 1] == k - 1) m[0][2 * i] = 1;

	//j - ая миссия играется после i - ой. Сложность j - ой миссии должна быть больше i - ой.
	//j - ая миссия должна находиться в НВП на одну позицию дальше i - ой. Если это так,
	//то проводим ориентированное ребро между миссиями(строим ребра между ярусами).
	for (i = 0; i < g.size(); i++)
		for (j = i + 1; j < g.size(); j++)
			if (v[i].first < v[j].first && g[i] == g[j] - 1) m[2 * (j + 1) - 1][2 * (i + 1)] = 1;

	//Ищем максимальный поток на построенной сети.
	MaxFlow = 0;
	do
	{
		memset(used, 0, sizeof used);
	} while ((flow = aug(0, 2 * n + 1, 0x7FFFFFFF)) && (MaxFlow += flow));

	//Максимальное количество миссий, которое может быть завершено, равно
	//величине максимального потока MaxFlow, умноженному на длину k НВП.
	printf("%d\n", k*MaxFlow);
	return 0;
}
