#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
	vector<int> go;
	bool terminal;
	vector<pair<int, int>> there;
	node() {
		go.resize(26, -1);
		terminal = false;
	}
};

vector<node> trie;

int add_node() {
	trie.push_back(node());
	return int(trie.size()) - 1;
}

vector<string> a, b;

int add_string(int v, int id, int pos) {
	for (; pos < int(b[id].size());) {
		if (trie[v].terminal) {
			v = 0;
			continue;
		}
		if (trie[v].go[b[id][pos] - 'a'] == -1) {
			trie[v].there.push_back({ id, pos });
			return 0;
		}
		v = trie[v].go[b[id][pos] - 'a'];
		++pos;
	}
	if (pos == int(b[id].size())) return trie[v].terminal;
	trie[v].there.push_back({ id, pos });
	return 0;
}

int main() {
	char s[1000001];
	trie.push_back(node());
	int q;
	scanf("%d", &q);
	int last = 0;
	for (int i = 0; i < q; ++i) {
		char c;
		scanf("\n%c%s", &c, s);
		int l = strlen(s);
		rotate(s, s + last % l, s + l);
		if (c == '+') {
			int v = 0;
			vector<int> ans;
			for (int j = 0; j < l; ++j) {
				int d = s[j] - 'a';
				if (trie[v].go[d] != -1) {
					v = trie[v].go[d];
					continue;
				}
				vector<pair<int, int>> rest;
				int u = trie[v].go[d] = add_node();
				for (auto p : trie[v].there) {
					if (b[p.first][p.second] == d + 'a') {
						if (int(b[p.first].size()) > p.second + 1) {
							++p.second;
							trie[u].there.push_back(p);
						}
						else if (j == l - 1) ans.push_back(p.first);
					}
					else rest.push_back(p);
				}
				trie[v].there = rest;
				v = u;
			}
			trie[v].terminal = true;
			for (auto p : trie[v].there) {
				if (add_string(0, p.first, p.second)) ans.push_back(p.first);
			}
			trie[v].there.clear();
			last = int(ans.size());
			cout << int(ans.size()) << " ";
			for (int num : ans) cout << num + 1 << " ";
			cout << "\n";
		}
		else {
			b.push_back(s);
			if (add_string(0, int(b.size()) - 1, 0)) {
				cout << 1 << " " << int(b.size()) << "\n";
				last = 1;
			}
			else {
				cout << 0 << "\n";
				last = 0;
			}
		}
	}
	return 0;
}
