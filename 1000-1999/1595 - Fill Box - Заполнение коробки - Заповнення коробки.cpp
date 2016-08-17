#include <iostream>
#include <vector>

using namespace std;

vector<int> cubes;

//Функция minCubes возвращает наименьшее количество кубов, которыми можно
//полностью заполнить коробку, или - 1, если этого совершить невозможно.
int minCubes(int length, int width, int height)
{
	long done = 0;
	int res = 0;
	for (int i = cubes.size() - 1; i >= 0; i--)
	{
		int len = 1 << i;

		//Вычисляем количество amount кубов размера 2^i * 2^i * 2^i, которое можно положить в коробку.
		int amount = (length / len) * (width / len) * (height / len);

		//Поскольку до этого в коробку уже положено done кубов со стороной 2^i,
		//то еще в нее может войти максимум amount – done кубов со стороной 2^i.
		amount -= done;

		//Если amount больше количества имеющихся кубов со стороной 2^i,
		//то максимум мы можем положить в коробку cubes[i] кубов.
		if (amount > cubes[i]) amount = cubes[i];

		//К done кубов со стороной 2^i кладем amount кубов с такой же длиной стороны.
		//Далее считаем, что у нас в коробке находится(done + amount) * 8 кубов со стороной 2^(i - 1).
		done = (done + amount) * 8;
		res += amount;
	}
	//По окончанию цикла переменная done содержит количество кубов со стороной 1 / 2,
	//которое положено в коробку.Если объем положенных кубов меньше объема коробки,
	//то заполнить коробку не удалось, поэтому возвращаем - 1.
	if (done < 8L * length * width * height) return -1;
	return res;
}

int main() {
	int length, width, height, k;
	while (scanf("%d %d %d %d", &length, &width, &height, &k) == 4)
	{
		cubes.resize(k);
		for (int i = 0; i < k; i++) scanf("%d", &cubes[i]);
		printf("%d\n", minCubes(length, width, height));
	}
	return 0;
}
