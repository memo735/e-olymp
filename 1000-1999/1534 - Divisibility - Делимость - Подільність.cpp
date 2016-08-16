#include <iostream>

using namespace std;


int a[20], n, l, r;

int gcd(int A, int B)
{
	if (B == 0) return A;
	return gcd(B, A % B);
}

int f(int N, int *a)
{
	int i, j, bits, temp, res = 0;
	long lcm;
	for (i = 1; i < 1 << n; i++)
	{
		lcm = 1; bits = 0;
		for (j = 0; j < n; j++)
			if (i & 1 << j)
			{
				bits++;
				temp = gcd(lcm, a[j]);
				lcm = lcm / temp * a[j];
				if (lcm > N) break;
			}
		if (bits % 2) res += N / lcm;
		else res -= N / lcm;
	}
	return res;
}

int main() {
	while (scanf("%d %d", &l, &r) == 2)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		printf("%d\n", f(r, a) - f(l - 1, a));
	}
	return 0;
}
