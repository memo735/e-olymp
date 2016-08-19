#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 0xFFFFFFFF

int n, p, Cost, i, mask, x;
unsigned int m[15], MinCost[1 << 14];

//Для маски mask следует перебрать все подмаски sub, вычислим минимум среди всех возможных сумм FindCost(sub) + FindCost(mask ^ sub).Ввиду симметрии суммы достаточно перебирать только те подмаски sub, для которых sub ≥ mask ^ sub.
unsigned int FindCost(int mask)
{
	if (MinCost[mask] != MAX) return MinCost[mask];
	// sub перебирает все подмаски маски mask
	for (int sub = (mask - 1) & mask; sub >= mask ^ sub; sub = (sub - 1) & mask)
		MinCost[mask] = min(MinCost[mask], FindCost(sub) + FindCost(mask ^ sub));
	return MinCost[mask];
}

//Теорема.Перебор всех масок, а для них подмасок выполняется за O(3^n).
//Доказательство 1. Рассмотрим i - ый бит. Для него имеется три варианта :
//·         он входит в маску mask и подмаску sub;
//·         он входит в маску mask но не входит в подмаску sub;
//·         он не входит ни в маску mask, ни в подмаску sub;
//Всего битов n, поэтому различных комбинаций 3^n.
//Доказательство 2. Пусть маска mask имеет k включенных битов. Тогда она будет иметь 2^k подмасок.
//Количество масок длины n с k включенными битами равно C(k,n). Следовательно число комбинаций равно
//sum(k=0..n) (C(k,n)*2^k)= (1 + 2)^n = 3^n

int main()
{
	//Установим MinCost[mask] = -1, если стоимость отправки набора
	//предметов, которые задаются подмножеством mask, еще не вычислена.

	memset(MinCost, 0xFF, sizeof MinCost);
	scanf("%d %d", &n, &p);
	for (i = 0; i < n; i++) scanf("%d", &m[i]);

	//Если стоимость некоторого подмножества предметов не больше 1000
	//(именно не больше, а не меньше так как возможен случай p = 1000),
	//то специальное предложение для их отправки не может быть использовано.
	//Для таких подмножеств сразу можно вычислить MinCost[mask] как сумму
	//стоимостей всех предметов.Если сумма стоимостей предметов равна в
	//точности 1000, то положим MinCost[mask] = p.
	for (mask = 0; mask < (1 << n); mask++)
	{
		for (Cost = i = 0; i < n; i++) if (mask & (1 << i)) Cost += m[i];
		if (Cost == 1000) Cost = p;
		if (Cost <= 1000) MinCost[mask] = Cost;
	}
	printf("%u\n", FindCost((1 << n) - 1));
	return 0;
}
