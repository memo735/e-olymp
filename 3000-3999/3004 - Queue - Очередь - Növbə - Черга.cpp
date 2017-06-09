#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset <long> v;
	long temp, n, k, i, a;
	scanf("%ld %ld", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%ld", &a);
		if (v.size() != k) v.insert(a);
		else {
			temp = *v.begin();
			v.erase(v.begin());
			v.insert(temp + a);
		}
	}
	multiset<long>::iterator end = v.end();
	--end;
	printf("%ld", *end);
}
