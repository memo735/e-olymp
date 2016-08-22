#include <iostream>
#include <bitset>

using namespace std;

bitset<10001> mask;

int main() {
	//Читаем входные данные. Устанавливаем mask[0] = 1.
	int i, j, n, m, w;
	scanf("%d %d", &m, &n);
	mask.set(0);

	//Обработка очередного предмета весом w. Проходим по массиву m справа налево и
	//устанавливаем в 1 все такие mask[i] (w ≤ i ≤ s), для которых mask[i – w] = 1.
	for (i = 0; i < n; i++)
	{
		scanf("%d", &w);
		for (j = m; j >= w; j--)
			if (mask[j - w] == 1) mask.set(j);
	}
	//Ищем наибольший вес (не больший m), который можно отправить в багаж, и выводим его.
	for (i = m;; i--) if (mask[i] > 0) break;
	printf("%d\n", i);
	return 0;
}
