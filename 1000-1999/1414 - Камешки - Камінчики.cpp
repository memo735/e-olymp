#include <iostream>

using namespace std;

int gcd(int A, int B)
{
	if (B == 0) return A;
	return gcd(B, A % B);
}

int main() {
	int a, d, n, m;
	scanf("%d %d", &n, &m);
	scanf("%d", &d);
	while (n-- > 1)
	{
		scanf("%d", &a);
		d = gcd(d, a);
	}
	puts(m % d == 0 ? "YES" : "NO");
	return 0;
}
