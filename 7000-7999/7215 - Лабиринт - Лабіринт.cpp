#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define SIZE 2000

int dist[SIZE][SIZE], n, m;
string g[SIZE];
vector <pair<pair<int, int>, int> > que;
vector <pair<int, int> > way;

void check(int x, int y, int ind) {
	if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == ' ' && !dist[x][y]) {
		dist[x][y] = 1;
		que.push_back(make_pair(make_pair(x, y), ind));
	}
}

bool isExit(int x, int y) {
	return (x == 0 || x == n - 1 || y == 0 || y == m - 1) && (g[x][y] == ' ' || g[x][y] == '+');
}

int main() {
	cin >> n >> m;
	getline(cin, g[0]);
	for (int i = 0; i < n; i++) {
		getline(cin, g[i]);
		for (int j = 0; j < m; j++)
			if (g[i][j] == '+') {
				que.push_back(make_pair(make_pair(i, j), -1));
				dist[i][j] = 1;
			}
	}
	for (int i = 0; i < que.size(); i++) {
		if (isExit(que[i].first.first, que[i].first.second)) {
			while (i != -1) {
				way.push_back(make_pair(que[i].first.first, que[i].first.second));
				i = que[i].second;
			}
			break;
		}
		check(que[i].first.first - 1, que[i].first.second, i);
		check(que[i].first.first + 1, que[i].first.second, i);
		check(que[i].first.first, que[i].first.second - 1, i);
		check(que[i].first.first, que[i].first.second + 1, i);
	}
	if (way.size()) {
		cout << way.size() - 1 << endl;
		for (int i = way.size() - 1; i; i--) {
			if (way[i].first == way[i - 1].first - 1) cout << "s";
			if (way[i].first == way[i - 1].first + 1) cout << "n";
			if (way[i].second == way[i - 1].second - 1) cout << "e";
			if (way[i].second == way[i - 1].second + 1) cout << "w";
		}
		if (way.size() > 1) cout << endl;
	}
	else cout << "-1\n";
	return 0;
}
