#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 70001

int i, n, q, l, r, x;

struct city
{
	int people, num;
	city(int people = 0, int num = 0) { this->people = people; this->num = num; }
} a[MAX];

//Сортируем города по увеличению числа перевезенных людей. Если городов с одинаковым
//количеством перевезенных людей несколько, то сортируем их по возрастанию номеров.
int f(city a, city b)
{
	if (a.people == b.people) return a.num < b.num;
	return a.people < b.people;
}

//Ищем позицию Left пары city(x, l) по нижней границе и позицию Right пары city(x, r) по верхней
//границе. Если они совпадают – то искомого города не существует. Иначе существует город, в котором
//трамваи перевезли в точности x пассажиров, причем его номер лежит от l до r включительно.
int Query(int l, int r, int x)
{
	int Left = lower_bound(a, a + n, city(x, l), f) - a;
	int Right = upper_bound(a, a + n, city(x, r), f) - a;
	return Left < Right;
}

int main() {
	//Считываем информацию о перевезенных людях в городах.
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i].people), a[i].num = i + 1;
	sort(a, a + n, f);
	//Обрабатываем q запросов.
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d %d %d", &l, &r, &x);
		printf("%d", Query(l, r, x));
	}
	printf("\n");
	return 0;
}
