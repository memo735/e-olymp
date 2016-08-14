#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define INF 2000000000

int e, n, m, stations, PrevStation, CurStation, PrevTime, CurTime;

class Prior
{
public:
	int Time, Vertex;
	Prior(int Time, int Vertex) : Time(Time), Vertex(Vertex) {}
	int operator< (const Prior &a) const { return Time < a.Time; }
	int operator> (const Prior &a) const { return Time > a.Time; }
};

//Объявим класс ребро, соединяющие две соседние станции. Оно содержит следующие атрибуты :
//·        vTo – номер станции, куда едет электричка;
//·        timeFrom – время отправления электрички из текущей станции;
//·        timeTo – время прибытия электрички на станцию vTo;
class Edge
{
public:
	int vTo, timeFrom, timeTo;
	Edge(int vTo, int timeFrom, int timeTo) : vTo(vTo), timeFrom(timeFrom), timeTo(timeTo) {}
};

//Объявим класс граф. Он содержит количество вершин n и задается списком смежности g.
class Graph
{
public:
	int n;
	vector<vector<Edge> > g;
	Graph(int n = 1) : n(n)
	{
		g = vector<vector<Edge> >(n);
	}

	//Функция добавления ориентированного ребра(From, To).
	//Электричка выезжает со станции From в момент времени timeFrom  и прибывает на станцию To в момент времени timeTo.
	void AddEdge(int From, int To, int timeFrom, int timeTo)
	{
		g[From].push_back(Edge(To, timeFrom, timeTo));
	}

	//Алгоритм Дейкстры запускается из вершины Source.
	//Вторым аргументом передается массив time : time[i] содержит наименьшее время,
	//за которое можно добраться на электричках из вершины Source в i.
	void Dijkstra(int Source, vector<int> &time)
	{
		priority_queue<Prior, vector<Prior>, greater<Prior> > pq;

		//Кладем в очередь пару(0, Source), полагаем время time[Source] равным 0
		//(добраться от вершины Source до ее же самой можно за нулевое время).
		pq.push(Prior(0, Source)); time[Source] = 0;
		while (!pq.empty())
		{
			int v = pq.top().Vertex, d = pq.top().Time;
			pq.pop();

			//Проверяем, не является ли извлеченная из головы очереди пара(v, d) фиктивной.
			if (d > time[v]) continue;

			//Просматриваем вершины to, смежные с v.Пробуем провести релаксацию ребра(v, to).
			for (int i = 0; i < g[v].size(); i++)
			{
				//time[v] содержит наименьшее время, за которое можно доехать до станции v.
				//Если ребро(v, to) содержит информацию, что электричка выезжает из v в to раньше,
				//чем time[v], то мы на эту электричку не успеваем.

				if (g[v][i].timeFrom < time[v]) continue;
				//Вычисляем станцию to, в которое ведет ребро.

				int to = g[v][i].vTo;
				//Если до станции to по ребру(v, to) можно добраться за меньшее время,
				//нежели уже имеется в time[to], то проводим релаксацию и заносим пару(time[to], to) в очередь.

				if (time[to] > g[v][i].timeTo)
				{
					time[to] = g[v][i].timeTo;
					pq.push(Prior(time[to], to));
				}
			}
		}
	}
};
Graph *g;

int main() {
	//Инициализируем массив time, содержащий кратчайшее время, за которое можно добраться до всех станций из начальной.
	scanf("%d %d %d", &n, &e, &m);
	g = new Graph(n + 1);
	auto time = vector<int>(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &stations); PrevStation = -1;
		for (int j = 0; j < stations; j++)
		{
			scanf("%d %d", &CurStation, &CurTime);

			//Электричка выезжает со станции PrevStation в момент времени PrevTime и
			//движется на следующую станцию CurStation, на которую прибывает в момент времени CurTime.
			if (PrevStation != -1) g->AddEdge(PrevStation, CurStation, PrevTime, CurTime);
			PrevStation = CurStation; PrevTime = CurTime;
		}
	}
	g->Dijkstra(1, time);
	if (time[e] == INF) printf("-1\n");
	else printf("%d\n", time[e]);
	return 0;
}
