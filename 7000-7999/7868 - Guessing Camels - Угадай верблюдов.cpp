#include <iostream>
#include <math.h>

using namespace std;

#define MAXN 200001
#define lowbit(x) (x & -x)

int n, c[MAXN], p1[MAXN], p2[MAXN], p3[MAXN], pos[MAXN];

void add(int x, int delta) {
	for (; x <= n; x += lowbit(x)) c[x] += delta;
}

int query(int x)
{
	int ret = 0;
	for (; x; x -= lowbit(x)) ret += c[x];
	return ret;
}

void in(int &x)
{
	x = 0;
	char ch = getchar();
	while (!('0' <= ch && ch <= '9')) ch = getchar();
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}

int main()
{
	in(n); long ans = 1L * n*(n - 1);
	for (int i = 1; i <= n; i++)  in(p1[i]);
	for (int i = 1; i <= n; i++)  in(p2[i]);
	for (int i = 1; i <= n; i++)  in(p3[i]);
	for (int i = 1; i <= n; i++)  pos[p1[i]] = i, c[i] = 0;
	for (int i = n; i; i--) ans -= query(pos[p2[i]]), add(pos[p2[i]], 1);
	for (int i = 1; i <= n; i++)  pos[p2[i]] = i, c[i] = 0;
	for (int i = n; i; i--) ans -= query(pos[p3[i]]), add(pos[p3[i]], 1);
	for (int i = 1; i <= n; i++)  pos[p3[i]] = i, c[i] = 0;
	for (int i = n; i; i--) ans -= query(pos[p1[i]]), add(pos[p1[i]], 1);
	cout << (ans >> 1) << endl;
}
