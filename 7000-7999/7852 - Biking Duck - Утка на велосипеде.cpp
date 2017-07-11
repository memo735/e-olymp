#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	double x, y;
	point() : x(0.0), y(0.0) {}
	point(double x_, double y_) : x(x_), y(y_) {}
};

point operator+ (point a, point b) { return point(a.x + b.x, a.y + b.y); }

point operator* (double a, point b) { return point(a*b.x, a*b.y); }

double solution, v_walk, v_metro, x_min, y_min, x_max, y_max;
point start, endp;
int num_metro;
vector<point> metro;

double dist(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

point boundary_point(int index) {
	if (index % 4 == 0) return point(x_min, y_min);
	if (index % 4 == 1) return point(x_max, y_min);
	if (index % 4 == 2) return point(x_max, y_max);
	return point(x_min, y_max);
}

double time_to_station(point foot, point metro) {
	double result = dist(foot, metro) / v_walk;
	for (int b = 0; b < 4; b++) {
		point lo = boundary_point(b);
		point hi = boundary_point(b + 1);
		for (int times = 0; times < 100; times++) {
			point p1 = 2.0 / 3.0 * lo + 1.0 / 3.0 * hi;
			point p2 = 1.0 / 3.0 * lo + 2.0 / 3.0 * hi;
			double t1 = dist(foot, p1) / v_walk + dist(p1, metro) / v_metro;
			double t2 = dist(foot, p2) / v_walk + dist(p2, metro) / v_metro;
			t1 < t2 ? hi = p2 : lo = p1;
			result = min(result, (t1 + t2) / 2.0);
		}
	}
	return result;
}

double time_without_stations(point foot1, point foot2) {
	double result = dist(foot1, foot2) / v_walk;
	for (int b = 0; b < 4; b++) {
		point lo = boundary_point(b), hi = boundary_point(b + 1);
		for (int times = 0; times < 100; times++) {
			point p1 = 2.0 / 3.0 * lo + 1.0 / 3.0 * hi;
			point p2 = 1.0 / 3.0 * lo + 2.0 / 3.0 * hi;
			double t1 = dist(foot1, p1) / v_walk + time_to_station(foot2, p1);
			double t2 = dist(foot1, p2) / v_walk + time_to_station(foot2, p2);
			t1 < t2 ? hi = p2 : lo = p1;
			result = min(result, (t1 + t2) / 2.0);
		}
	}
	return result;
}

int main() {
	cin >> v_walk >> v_metro;
	cin >> x_min >> y_min >> x_max >> y_max;
	cin >> start.x >> start.y;
	cin >> endp.x >> endp.y;
	cin >> num_metro;
	metro = vector<point>(num_metro);
	for (int i = 0; i < num_metro; i++) cin >> metro[i].x >> metro[i].y;
	solution = time_without_stations(start, endp);
	vector<double> time_from(num_metro), time_to(num_metro);
	for (int i = 0; i < num_metro; i++) {
		time_from[i] = time_to_station(start, metro[i]);
		time_to[i] = time_to_station(endp, metro[i]);
	}
	for (int i = 0; i < num_metro; i++) {
		for (int j = 0; j < num_metro; j++) {
			solution = min(solution, time_from[i] + dist(metro[i], metro[j]) / v_metro + time_to[j]);
		}
	}
	cout << setprecision(10) << solution << endl;
	return 0;
}
