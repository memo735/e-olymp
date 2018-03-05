#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const ull MODULE = 10;

using mat_t = ull[2][2];
using vec_t = ull[2];

mat_t fibomat = {
	{ 0, 1 },
	{ 1, 1 },
};

ull mod(ull v) {
	return v % MODULE;
}

void mulmat(mat_t a, mat_t b, mat_t &r) {
	r[0][0] = mod(mod(a[0][0] * b[0][0]) + mod(a[0][1] * b[1][0]));
	r[0][1] = mod(mod(a[0][0] * b[0][1]) + mod(a[0][1] * b[1][1]));
	r[1][0] = mod(mod(a[1][0] * b[0][0]) + mod(a[1][1] * b[1][0]));
	r[1][1] = mod(mod(a[1][0] * b[0][1]) + mod(a[1][1] * b[1][1]));
}

void mulvec(vec_t a, mat_t b, vec_t &r) {
	r[0] = mod(mod(a[0] * b[0][0]) + mod(a[1] * b[1][0]));
	r[1] = mod(mod(a[0] * b[0][1]) + mod(a[1] * b[1][1]));
}

void matpow(mat_t m, ull n, mat_t &r) {
	if (n == 1) {
		r[0][0] = m[0][0];
		r[0][1] = m[0][1];
		r[1][0] = m[1][0];
		r[1][1] = m[1][1];
	} else if (n % 2 == 1) {
		mat_t t;
		matpow(m, n - 1, t);
		mulmat(m, t, r);
	} else {
		mat_t t;
		matpow(m, n / 2, t);
		mulmat(t, t, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ull n;
	while (cin >> n) {
		if (n == 0) {
			out << 1 << endl;
		} else if (n == 1) {
			out << 1 << endl;
		} else {
			vec_t start = {1, 1}, v;
			mat_t m;
			matpow(fibomat, n - 1, m);

			mulvec(start, m, v);
			out << v[1] << endl;
		}
	}

	return 0;
}