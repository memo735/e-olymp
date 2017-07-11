#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sgn(int x) { return (x > 0) - (x < 0); }

struct point {
	int x, y, side;
	point(int x = 0, int y = 0) : x(x), y(y) {}
	int cross(const point p) const { return p.x*y - x*p.y; }
	int turn(const point p) const { return sgn(cross(p)); }
	point operator-(const point p) const { return point(x - p.x, y - p.y); }
	int dot(const point p) const { return x*p.x + y*p.y; }
	double dist() const { return sqrt(dot(*this)); }
	bool operator==(const point p) const { return x == p.x && y == p.y; }
};

void read(vector<point> &P, int sgn) {
	int n;
	scanf("%d", &n);
	point p;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p.x, &p.y);
		p.side = sgn;
		P.push_back(p);
	}
}

bool inside(point p, point A, point B, point C) {
	int a = (B - A).turn(p - A);
	return a == (C - B).turn(p - B) && a == (A - C).turn(p - C);
}

double perimeter(const vector<point> &P) {
	double res = 0;
	for (int i = 0, j = P.size() - 1; i < P.size(); j = i++) res += (P[j] - P[i]).dist();
	return res;
}

vector<point> all;

bool contract(vector<point> &track) {
	int n = track.size();
	for (int i = 0, j = n - 1, k = n - 2; i < n; k = j, j = i++) {
		int t = (track[j] - track[k]).turn(track[i] - track[j]);
		if (track[j].side > 0 && t > 0) {
			vector<point> obstacles({ track[k], track[i] }), hull;
			for (auto p : all) if (inside(p, track[i], track[j], track[k])) obstacles.push_back(p);
			sort(obstacles.begin() + 1, obstacles.end(),
				[k, track](point p, point q) {
				int tt = (p - track[k]).turn(q - track[k]);
				if (tt) return tt > 0;
				return (p - track[k]).dist() < (q - track[k]).dist(); });
			for (auto p : obstacles) {
				while (hull.size() > 2 && (hull.back() - *(hull.end() - 2)).turn(p - hull.back()) < 0) hull.pop_back();
				hull.push_back(p);
			}
			for (auto t1 : track) // avoid messing up track by causing self-intersection
				if (find(hull.begin() + 1, hull.end() - 1, t1) != hull.end() - 1) goto next;
			track.erase(track.begin() + j);
			track.insert(track.begin() + j, hull.begin() + 1, hull.end() - 1);
			return true;
		}
	next:;
	}
	return false;
}

int main() {
	read(all, 1);
	vector<point> track = all;
	read(all, -1);
	while (contract(track));
	printf("%.9lf\n", perimeter(track));
	return 0;
}
