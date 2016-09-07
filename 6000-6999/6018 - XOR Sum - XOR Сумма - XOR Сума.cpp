#include <iostream>
#include <queue>
#include <functional>

using namespace std;

priority_queue<long, vector<long>, greater<long> > pq;
char com[20];
long i, k, n, t, q, xor1;

int main() {
	scanf("%ld", &t);
	while (t--)
	{
		scanf("%ld %ld\n", &q, &k);

		//Перед обработкой очередного теста чистим кучу, обнуляем значение переменной xor1.
		xor1 = 0;
		while (pq.size() > 0) pq.pop();
		for (i = 0; i < q; i++)
		{
			scanf("%s", com);

			//При поступлении команды insert заносим число n в кучу, обновляем переменную xor1.
			if (com[0] == 'i')
			{
				scanf("%ld\n", &n);
				xor1 ^= n;
				pq.push(n);
			}
			else
			{
				//Удаляем все числа, не входящие в k максимальных, пересчитывая
				//xor1. Метод pop удаляет наименьшее число из кучи.
				while (pq.size() > k)
				{
					xor1 ^= pq.top();
					pq.pop();
				}
				printf("%ld\n", xor1);
			}
		}
	}
	return 0;
}
