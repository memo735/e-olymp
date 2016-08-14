#include <iostream>
#include <deque>
#include <map>
#include <set>

using namespace std;

int price[101], weight[2001];
set<int> s;
map<int, int> mp;
deque<int> d;


int main() {
	int i, n, m, car, res;
	scanf("%d %d", &n, &m);

	//Занесем во множество s список свободных парковочных мест. Изначально все парковки от 1 до n свободны.
	for (i = 1; i <= n; i++) s.insert(i);

	//Считываем стоимость парковочных мест и веса автомобилей.
	for (i = 1; i <= n; i++) scanf("%d", &price[i]);
	for (i = 1; i <= m; i++) scanf("%d", &weight[i]);

	//Последовательно читаем и обрабатываем команды о приезде и выезде автомобилей.
	for (res = 0, i = 1; i <= 2 * m; i++)
	{
		scanf("%d", &car);

		//Автомобиль заезжает на парковку
		if (car > 0)
		{
			//Если множество s не пусто, то имеется хотя бы одно свободное парковочное место.
			if (!s.empty())
			{
				//Присваиваем ParkingPlace наименьший номер свободного парковочного места
				auto ParkingPlace = *s.begin();

				//К результату res прибавляем прибыль парковщика.
				res += weight[car] * price[ParkingPlace];

				//На место s.begin() только что приехала машина.Отмечаем его занятым – удаляем из множества s.
				s.erase(s.begin());

				//Автомобиль с номером car только что поставили на парковку номер ParkingPlace
				mp[car] = ParkingPlace;
			}
			else
			{
				//Свободных парковочных мест нет, заносим автомобиль в очередь d.
				d.push_back(car);
			}
		}
		else
		{
			//Рассмотрим случай, когда car < 0. Автомобиль с номером - car выезжает из парковки с номером mp[-car].
			//Номер парковки, на которой находится автомобиль с номером - car, находим за время O(log2n) при помощи отображения mp.
			auto ParkingPlace = mp[-car];

			//Если имеется очередь ждущих машин, то следует завести первую в
			//очереди машину на только что освободившееся место ParkingPlace.
			if (!d.empty())
			{
				car = d[0];
				res += weight[car] * price[ParkingPlace];
				mp[car] = ParkingPlace;
				d.pop_front();
			}
			//Если в очереди никого нет, то просто освобождаем парковочное место ParkingPlace.
			else s.insert(ParkingPlace);
		}
	}
	printf("%d\n", res);
	return 0;
}
