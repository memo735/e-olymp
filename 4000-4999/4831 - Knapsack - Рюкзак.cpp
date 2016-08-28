#include <iostream>
#include <string.h>

using namespace std;

int i, s, w, m[10001];

int main() {
	scanf("%d", &s);
	memset(m, 0, sizeof m);
	m[0] = 1;
	//Обработка очередного слитка весом w. Проходим по массиву m справа налево
	//и устанавливаем в 1 все такие m[i] (w ≤ i ≤ s), для которых m[i - w] = 1.
	while (scanf("%d", &w) == 1)
	{
		for (i = s; i >= w; i--) if (m[i - w] == 1) m[i] = 1;
	}
	//Ищем наибольший вес(не больший s), который можно унести в рюкзаке, и выводим его.
	for (i = s;; i--) if (m[i] > 0) break;
	printf("%d\n", i);
	return 0;
}
