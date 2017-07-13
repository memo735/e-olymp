#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	set <int> r, c;
	long sr = n * 1L * (n + 1) / 2;
	long nr = n, sc = sr, nc = n;
	while (q--) {
		char ch = getchar();
		while (ch != 'R' && ch != 'C') ch = getchar();
		int id;
		scanf("%d", &id);
		if (ch == 'R') {
			if (r.find(id) != r.end()) printf("0\n");
			else {
				r.insert(id);
				printf("%ld\n", sc + id * nc);
				sr -= id;
				nr--;
			}
		}
		else {
			if (c.find(id) != c.end()) printf("0\n");
			else {
				c.insert(id);
				printf("%ld\n", sr + id * nr);
				sc -= id;
				nc--;
			}
		}
	}
	return 0;
}
