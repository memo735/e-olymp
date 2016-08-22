#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001

vector<long> Fenwick;
int i, n, value, tests;
long sum;

//Вычисление суммы a0 + a1 + ... + ai.
long Summma0_i(int i)
{
	long z = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) z += Fenwick[i];
	return z;
}

//Увеличение элемента : ai = ai + delta.
void IncElement(int i, int delta)
{
	for (; i < MAX; i = i | (i + 1)) Fenwick[i] += delta;
}

int main() {
	//Читаем входные данные. Заполняем массив Fenwick нулями.
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		Fenwick.assign(MAX, 0);
		for (sum = i = 0; i < n; i++)
		{
			//Для каждого значения value, записанного на ступеньке, увеличиваем avalue
			//на value, а также подсчитываем сумму чисел, записанных ранее на ступеньках
			//и меньших value. Эта сумма равна a0 + a1 + a2 + … + avalue - 1.
			scanf("%d", &value);
			IncElement(value, value);
			sum += Summma0_i(value - 1);
		}
		//Выводим сумму всех чисел, записанных в дневнике детектива.
		printf("%ld\n", sum);
	}
	return 0;
}
