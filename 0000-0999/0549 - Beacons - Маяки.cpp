#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

typedef vector<bool> Vb;
typedef vector<double> Vd;
typedef vector<int> Vi;
typedef vector<Vb> Mb;

const double PI = acos(-1.0);

struct Point {
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	double x, y;
};

Point operator-(const Point& p1, const Point& p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
double norm(const Point& v) { return sqrt(v.x*v.x + v.y*v.y); }
double sqr(double x) { return x*x; }

struct Circle {
	Point p;
	double r;
};

int n, m;
vector<Point> beacons;
vector<Circle> peaks;

vector<vector<bool>> S; // S[i][j]=1 if beacons i and j are in sight of each other
vector<bool> vis;

void dfs(int i) {
	if (vis[i]) return;
	vis[i] = true;
	for (int j = 0; j < n; j++) if (S[i][j]) dfs(j);
}

// A data structure that maintains a union of intervals (a,b]
// on the real line. Adding new intervals and testing if a point
// is in the union is done in logarithmic time.
struct IntervalUnion {
	typedef map<double, double> Mdd;
	Mdd ints; // If a is in the map, ints[a] is the end of the interval starting at a.
	IntervalUnion() {
		const double Inf = numeric_limits<double>::max();
		ints[-Inf] = -Inf;
	}
	bool contains(double a) {
		Mdd::iterator l = ints.lower_bound(a);
		--l;
		return a <= l->second;
	}
	// Insert an interval (a,b] where a<b.
	void insert(double a, double b) {
		if (a >= b) return;
		Mdd::iterator l = ints.lower_bound(a);
		Mdd::iterator u = ints.upper_bound(b);
		--l, --u;
		double a2 = max(u->second, b);
		bool extend = (a <= l->second);
		if (extend) l->second = a2;
		++l, ++u;
		ints.erase(l, u);
		if (!extend) ints[a] = a2;
	}
};

vector<double> dists, relAngs;

bool cmpDist(int i, int j) { return dists[i] < dists[j]; }

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		beacons.push_back(p);
	}
	for (int i = 0; i < m; i++) {
		Circle c;
		cin >> c.p.x >> c.p.y >> c.r;
		peaks.push_back(c);
	}
	int nPoints = n + m;
	relAngs = dists = Vd(nPoints);
	Vi order(nPoints);
	for (int j = 0; j < nPoints; j++) order[j] = j;
	S = Mb(n, Vb(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Point v = beacons[j] - beacons[i];
			relAngs[j] = atan2(v.y, v.x) + PI;
			dists[j] = norm(v);
		}
		for (int j = 0; j < m; j++) {
			Point v = peaks[j].p - beacons[i];
			relAngs[n + j] = atan2(v.y, v.x) + PI;
			dists[n + j] = sqrt(sqr(norm(v)) - sqr(peaks[j].r));
		}
		sort(order.begin(), order.end(), cmpDist);
		IntervalUnion is;
		for (int j = 0; j < nPoints; j++) {
			int k = order[j];
			if (k < n) {
				bool b = is.contains(relAngs[k]);
				S[i][k] = S[k][i] = !b;
			}
			else {
				double a = relAngs[k], ad = atan(peaks[k - n].r / dists[k]);
				double a0 = fmod(a - ad + 2 * PI, 2 * PI), a1 = fmod(a + ad + 2 * PI, 2 * PI);
				if (a0 < a1) is.insert(a0, a1);
				else {
					is.insert(a0, 2 * PI);
					is.insert(0, a1);
				}
			}
		}
	}
	vis = Vb(n);
	int cnt = -1;
	for (int i = 0; i < n; i++)
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}

	cout << cnt << endl;
	return 0;
}
