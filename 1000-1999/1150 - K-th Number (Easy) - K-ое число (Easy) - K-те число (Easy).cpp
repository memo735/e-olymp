#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int i, j, k, n, m, len, a[101], temp[101];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int q = 0; q < m; q++)
	{
		scanf("%d %d %d", &i, &j, &k);
		len = j - i + 1;
		//Копируем a[i...j] в temp[0..j – i + 1] (всего(j – i + 1) * sizeof(int) байт), сортируем элементы массива temp.
		memcpy(temp, a + i - 1, len * sizeof(int));
		sort(temp, temp + len);
		printf("%d\n", temp[k - 1]);
	}
	return 0;
}
