#include <complex>
#include <iostream>

using namespace std;

int q[2001], r[2001];
complex<long> sp[2000], tp[1000];

int root(int a)
{
	return q[a] ? q[a] = root(q[a]) : a;
}

bool merge(int a, int b)
{
	a = root(a), b = root(b);
	return a^b ? r[a]<r[b] ? q[a] = b, ++r[b] : q[b] = a, ++r[a] : 0;
}

template <class T> long operator^(T a, T b) { return (a*conj(b)).imag(); }

bool collide(int a, int b) {
	return sp[a] != sp[b]
		&& (0L + sp[b] - sp[a] ^ tp[a] - sp[a]) * (tp[b] - sp[a] ^ tp[a] - sp[a]) <= 0
		&& (0L + sp[a] - sp[b] ^ tp[b] - sp[b]) * (tp[a] - sp[b] ^ tp[b] - sp[b]) <= 0;
}

int main() {
	int w, p; scanf("%d%d", &w, &p);
	for (int i = 0, a, b; i < w; i++) scanf("%d%d", &a, &b), sp[i + p] = { a,b };
	for (int i = p, a, b, c; i--;) scanf("%d%d%d", &a, &b, &c), sp[i] = sp[--a + p], tp[i] = { b,c };
	for (int i = p; i--;)
		for (int j = p; j--;)
			if (collide(i, j) && merge(i * 2 + 1, j * 2 + 2), root(i * 2 + 1) == root(i * 2 + 2))
				return !puts("impossible");
	return !puts("possible");
}
