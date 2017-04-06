#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	double h, w, res;
	scanf("%lf %lf", &w, &h);
	if (w < h) swap(w, h);
	res = w >= 3 * h ? h : max(h / 2, w / 3);
	printf("%.3lf\n", res);
	return 0;
}
