#include <stdio.h>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

#define SIZE 500
#define INF 0x3F3F3F3F

typedef pair<int, int> pii;

int a, b, len, n, m, k, source, tmp;
int winner[SIZE], g[SIZE][SIZE], d[SIZE];

set <pii> s;

int main(){
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		memset(g, 63, sizeof(g));// 63 = 0x3F
		memset(d, 63, sizeof(d));
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i<m; i++){
			scanf("%d", &tmp);
			winner[tmp] = 1;
		}
		for (int i = 0; i<k; i++){
			scanf("%d%d%d", &a, &b, &len);
			g[a][b] = len;
			g[b][a] = len;
		}
		scanf("%d", &source);
	}

	s.insert(pii(0, source));
	d[source] = 0;

	while (!s.empty()){
		pii top = *s.begin();
		int v = top.second;
		s.erase(s.begin());

		for (int i = 1; i <= n; i++){
			if (d[i] > d[v] + g[v][i]){
				if (d[i] != INF) s.erase(pii(d[i], i));
				d[i] = d[v] + g[v][i];
				s.insert(pii(d[i], i));
			}
		}
	}

	bool good_sponsore = true;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (winner[i])
			(d[i] == INF) ? good_sponsore = false :
			ans = max(ans, d[i]);
	}

	(good_sponsore) ? printf("The good sponsor!\n%d\n", ans) : printf("It is not fault of sponsor...\n");
}
