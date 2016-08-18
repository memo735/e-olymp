#include <iostream>

using namespace std;

int main() {
	int x0, y0, x1, y1, x2, y2;
	scanf("%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2);
	if ((x0 - x1) * (y2 - y1) == (x2 - x1) * (y0 - y1) &&
		(x0 - x1) * (x2 - x1) >= 0 && (y0 - y1) * (y2 - y1) >= 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
