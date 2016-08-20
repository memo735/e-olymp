#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 301

vector<vector<int> > graph;
vector<int> mt, used, used1, cell[MAX];
int a, b, i, j, ptr, cols, cuts, rows, flow;

int dfs(int v)
{
	if (used[v]) return 0;
	used[v] = 1;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int to = graph[v][i];
		if (mt[to] == -1 || dfs(mt[to]))
		{
			mt[to] = v;
			return 1;
		}
	}
	return 0;
}

void AugmentingPath()
{
	int i, j, to;
	mt.assign(cols, -1);
	used1.assign(rows, 0);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < graph[i].size(); j++)
		{
			to = graph[i][j];
			if (mt[to] == -1)
			{
				mt[to] = i;
				used1[i] = 1;
				break;
			}
		}
	}
	for (i = 0; i < rows; i++)
	{
		if (used1[i]) continue;
		used.assign(rows, 0);
		dfs(i);
	}
}

int main() {
	while (scanf("%d %d %d", &rows, &cols, &cuts) == 3)
	{
		graph.assign(rows, vector<int>());
		for (i = 0; i < MAX; i++) cell[i].clear();
		for (i = 0; i < cuts; i++)
		{
			scanf("%d %d", &a, &b);
			cell[a].push_back(b);
		}
		for (i = 0; i < rows; i++)
		{
			sort(cell[i].begin(), cell[i].end());
			cell[i].push_back(1000000000);
			for (ptr = j = 0; j < cols; j++)
			{
				if (cell[i][ptr] != j) graph[i].push_back(j);
				else while (cell[i][ptr] == j) ptr++;
			}
		}
		AugmentingPath();
		for (flow = i = 0; i < cols; i++) if (mt[i] != -1) flow++;
		printf("%d\n", flow);
	}
	return 0;
}
