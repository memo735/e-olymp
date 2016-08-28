#include <iostream>

using namespace std;

int i, k, n, a[1000001];
long res, Left, Right;

int main() {
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	//Подсчитываем количество требуемых интервалов согласно приведенному в анализе задаче алгоритму.
	Left = Right = res = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == k) res += i - Left + 1, Right = i;
		else
			if (a[i] < k && Right != 0) res += Right - Left + 1;
			else if (a[i] > k) Right = 0, Left = i + 1;
	}
	printf("%ld\n", res);
	return 0;
}
