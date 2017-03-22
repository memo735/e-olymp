#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Point {
	int x, y;
	Point(int x = -1, int y = -1) : x(x), y(y) {}
	bool operator< (const Point& o) const { return x < o.x || x == o.x && y < o.y; }
};

map<Point, char> table;
map<char, Point> pos;

int main() {
	string s;
	getline(cin, s);
	for (char c = 'a'; c <= 'z'; c++) if (c != 'q') s += c;
	Point nextPos(0, 0);
	for (int i = 0; i < s.size(); i++)
		if (s[i] != ' ' && pos[s[i]].x == -1) {
			pos[s[i]] = nextPos;
			table[nextPos] = toupper(s[i]);
			if (++nextPos.x == 5) nextPos = Point(0, nextPos.y + 1);
		}

	getline(cin, s);
	while (s.find(' ') != string::npos) s.erase(s.find(' '), 1);

	for (int i = 0; i < s.size(); i += 2)
		if (i == s.size() - 1 || s[i] == s[i + 1]) s.insert(i + 1, "x");

	for (int i = 0; i < s.size(); i += 2) {
		Point a = pos[s[i]];
		Point b = pos[s[i + 1]];
		if (a.y == b.y) {
			a.x = (a.x + 1) % 5;
			b.x = (b.x + 1) % 5;
		}
		else if (a.x == b.x) {
			a.y = (a.y + 1) % 5;
			b.y = (b.y + 1) % 5;
		}
		else swap(a.x, b.x);
		cout << table[a] << table[b];
	}
	cout << endl;
	return 0;
}
