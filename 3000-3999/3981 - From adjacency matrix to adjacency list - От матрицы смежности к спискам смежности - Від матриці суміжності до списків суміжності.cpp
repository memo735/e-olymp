#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
int i, j, n, val;

int main() {
	//Строим список смежности графа.
	scanf("%d", &n);
	g.resize(n + 1);
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &val);
			if (val) g[i].push_back(j);
		}
		for (i = 0; i < n; i++)
		{
			printf("%llu", g[i].size());
			for (j = 0; j < g[i].size(); j++) printf(" %d", g[i][j]);
			printf("\n");
		}
	}
	return 0;
}
