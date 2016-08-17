#include <iostream>

using namespace std;

int gather(int neededFood, int n, int price)
{
	int EWorkers, workers, food, days, best = 2000000000;
	if (n >= neededFood) return 1;
	for (EWorkers = n; EWorkers <= neededFood; EWorkers++)
	{
		//Изначально в нулевой день у нас 0 еды и n работников. Пока количество
		//собранной еды не достигло neededFood, моделируем процесс сбора. Каждый
		//день количество еды увеличивается на число имеющихся работников workers.
		food = days = 0; workers = n;
		while (food < neededFood)
		{
			food += workers;
			//Пока количество работников не достигло значения
			//EWorkers, всю собранную еду пускаем на найм.
			while (workers < EWorkers && food >= price) workers++, food -= price;
			days++;
		}
		if (days < best) best = days;
	}
	return best;
}

int main() {
	int neededFood, n, price;
	while (scanf("%d %d %d", &neededFood, &n, &price) == 3)
	{
		printf("%d\n", gather(neededFood, n, price));
	}
	return 0;
}
