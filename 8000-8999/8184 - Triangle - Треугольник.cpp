#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (d > f) swap(d, f);
	if (e > f) swap(e, f);
	if (d > e) swap(d, e);
	printf(a == d && b == e && c == f && a*a + b*b == c*c ? "YES\n" : "NO\n");
	return 0;
}
