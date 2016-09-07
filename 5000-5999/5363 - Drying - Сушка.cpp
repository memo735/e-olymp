#include <iostream>
#include <algorithm>

using namespace std;

int i, k, l, m, n, r, dry, a[100001];

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &k);

	//За r минут все белье обязательно высохнет даже без использования батареи.
	l = 0; r = *max_element(a, a + n);

	//Если k ≤ 1, то сушка с использованием радиатора эквивалентна сушке без него.
	if (k <= 1)
	{
		printf("%d\n", r);
		return 0;
	}
	//Ищем наименьшее количество минут m на промежутке[l; r] бинарным поиском.
	while (r - l > 1)
	{
		m = (r + l) / 2; dry = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] > m) dry += (a[i] - m + k - 2) / (k - 1);
			if (dry > m) break;
		}
		if (dry > m) l = m;
		else r = m;
	}
	printf("%d\n", r);
	return 0;
}
