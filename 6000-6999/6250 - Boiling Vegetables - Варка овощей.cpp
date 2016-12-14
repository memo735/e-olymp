#include <iostream>
#include <queue>

using namespace std;

struct vegetable
{
	double weight;
	int parts;
	vegetable(double weight, int parts) : weight(weight), parts(parts) {}
	int operator< (const vegetable &a) const
	{
		return weight / parts < a.weight / a.parts;
	}
};

//Сохраним куски в очереди с приоритетами heap.
priority_queue<vegetable> heap;

//Ищем вес минимального куска minWeight. Информацию о кусках 
//заносим в очередь : изначально все они разделены на 1 часть.
int main() {
	double t, w, minWeight = 1e10;
	int i, n;
	scanf("%lf %d", &t, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &w);
		heap.push(vegetable(w, 1));
		if (w < minWeight) minWeight = w;
	}
	//Количество разрезов подсчитываем в переменной cuts.
	int cuts = 0;
	while (true)
	{
		//Берем овощ с максимальным весом одной части cur.weight / cur.parts.
		vegetable cur = heap.top();
		//Если отношение весов минимальной minWeight и максимальной части не меньше t, то останавливаем процесс деления.
		if (minWeight / (cur.weight / cur.parts) >= t) break;
		heap.pop(); cuts++;
		//Увеличиваем количество разрезов в овоще cur.
		cur.parts++;
		//Пересчитываем вес минимальной части.
		minWeight = min(minWeight, cur.weight / cur.parts);
		//Заносим обновленный кусок в очередь.
		heap.push(cur);
	}
	printf("%d\n", cuts);
	return 0;
}
