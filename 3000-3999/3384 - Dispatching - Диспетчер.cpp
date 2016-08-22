#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100001

priority_queue<int> pq[MAX];
vector<vector<int>> g;
int i, n, m, parent, cost[MAX], leader[MAX];
long res, sum[MAX];

//Поиск в глубину из вершины v.Строим мультимножество pq[v].
void dfs(int v)
{
	int i, to;
	pq[v].push(cost[v]);
	sum[v] += cost[v];

	for (i = 0; i < g[v].size(); i++)
	{
		to = g[v][i];
		dfs(to);

		//Вершина to является сыном v. Занесем все элементы pq[to] в pq[v].
		//Размер очереди, куда будут переноситься числа, должен быть больше.
		if (pq[v].size() < pq[to].size()) swap(pq[v], pq[to]);

		//Переносим числа в pq[v], одновременно очищая в pq[to] для экономии памяти.
		while (pq[to].size() > 0)
		{
			pq[v].push(pq[to].top());
			pq[to].pop();
		}
		//Добавляем к sum[v] сумму чисел мультимножества потомка sum[to].
		sum[v] += sum[to];

		//На вершине очереди находятся большие числа (у нас max - куча). Удаляем их
		//пока сумма чисел в оставшемся мультимножестве не будет превышать бюджет m.
		while (sum[v] > m)
		{
			sum[v] -= pq[v].top();
			pq[v].pop();
		}
	}
	res = max(res, leader[v] * (long)pq[v].size());
}

int main() {
	//Читаем входной граф.
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &parent, &cost[i], &leader[i]);
		g[parent].push_back(i);
	}
	dfs(0);
	printf("%ld\n", res);
	return 0;
}
