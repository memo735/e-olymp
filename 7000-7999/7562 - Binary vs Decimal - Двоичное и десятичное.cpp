#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int B = 1;
const int fm = (1 << B) - 1;

void norm(vector<int>& c) {
	for (int i = 0; i < c.size() - 1; ++i) {
		c[i + 1] += c[i] >> B;
		c[i] &= fm;
	}
}

void trim(vi &c, int x) {
	c.resize(x / B + 1);
	c[x / B] &= (1 << (x % B)) - 1;
}

vi add(const vi &a, const vi &b, int k) {
	vi c(max(a.size(), b.size()) + 1);
	for (int i = 0; i < c.size(); ++i) {
		if (i < a.size()) c[i] += a[i];
		if (i < b.size()) c[i] += b[i];
	}
	norm(c);
	trim(c, k);
	return c;
}

int get_bit(const vi &v, int b) {
	return (v[b / B] >> (b % B)) & 1;
}

vector<int> mul(const vi& a, int x, int k)
{
	vector<int> b = a;
	b.push_back(0);
	for (int i = 0; i < b.size(); ++i) b[i] *= x;
	norm(b);
	trim(b, k);
	return b;
}

void gen(vector<int> n, const vector<vector<int>> &p, int k, int i, vector<pair<int, vector<int>> > &v) {
	if (i == k) {
		n.resize(k + 1);
		if (get_bit(n, k)) v.push_back(make_pair(k, n));
		return;
	}
	if (get_bit(n, i)) return;
	gen(n, p, k, i + 1, v);
	if (i) gen(add(n, p[i], k + 1), p, k, i + 1, v);
}

void print(const vi &v, int k) {
	for (int i = k; i >= 0; --i) cerr << get_bit(v, i);
	cerr << '\n';
}

int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	--n;

	vector<pair<int, vector<int>> > v;
	for (int k = 1; n / 2 >= v.size(); ++k) {
		vector<int> vekt(k / B + 1);
		vekt[k / B] = 1 << (k % B);
		vector<vector<int>> p(k + 1);
		p[0].push_back(1);
		trim(p[0], k + 1);
		for (int i = 0; i < k; ++i) p[i + 1] = mul(p[i], 10, k + 1);
		gen(vekt, p, k, 0, v);
	}
	for (int i = 0; i < v.size(); ++i) reverse(v[i].second.begin(), v[i].second.end());
	sort(v.begin(), v.end());
	vector<int> w = v[--n / 2].second;
	reverse(w.begin(), w.end());
	if (n & 1) w[0] ^= 1;
	for (int k = v[n / 2].first + 1 - 1; k >= 0; --k) cout << get_bit(w, k);
	cout << '\n';
	return 0;
}
