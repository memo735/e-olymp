#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <vector<int> > g;
vector <int> color, ans;
int n, a, b, root;

set<int>* dfs(int v){
	set<int> *cur = new set<int>, *t;
	cur->insert(color[v]);
	for (int i = 0; i < g[v].size(); i++){
		t = dfs(g[v][i]);
		if (cur->size() < t->size()) swap(cur, t);
		cur->insert(t->begin(), t->end());
		delete t;
	}
	ans[v] = cur->size();
	return cur;
}

int main(){
	scanf("%d", &n);
	g.resize(n);
	color.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		color[i] = b;
		if (a == 0) root = i;
		else g[a - 1].push_back(i);
	}
	dfs(root);
	printf("%d", ans[0]);
	for (int i = 1; i < n; i++) printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
