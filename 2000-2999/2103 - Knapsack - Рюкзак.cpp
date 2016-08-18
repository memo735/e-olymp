#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int i, n, s, w;
vector<int> cost;

int main() {
	scanf("%d %d", &w, &n);
	cost.assign(n, 0);
	for (i = 0; i < n; i++) scanf("%d", &cost[i]);

	//Сортируем полезности вещей по неубыванию.
	sort(cost.begin(), cost.end(), greater<int>());

	//Суммируем полезности вещей.
	for (s = i = 0; i < min(w, n); i++) s += cost[i];
	printf("%d\n", s);
	return 0;
}
