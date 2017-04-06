#include <iostream>
#include <vector>

using namespace std;

vector<long> go(long n)
{
	vector<long> temp;
	int i;
	//Разбираем случаи n = 0 и n = 1.
	if (n == 0) return temp;
	if (n == 1)
	{
		temp.push_back(1);
		return temp;
	}
	//Если n четное, то получаем разложение числа n / 2 в массиве t. Затем
	//умножаем каждое из полученных слагаемых на 2 и возвращаем массив temp.
	if (n % 2 == 0)
	{
		vector<long> t = go(n / 2);
		for (i = 0; i < t.size(); i++) temp.push_back(t[i] * 2);
		return temp;
	}
	//Число n нечетное.Найдем максимальное k, для которого three = 3k ≤ n.
	long three = 1;
	while (three * 3 <= n) three *= 3;
	//Далее раскладываем в требуемый вид число n –three.
	temp = go(n - three);
	//В полученный массив слагаемых добавим еще слагаемое three = 3k.
	temp.push_back(three);
	return temp;
}

int main() {
	int tests;
	long n;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%ld", &n);
		vector<long> res = go(n);
		//Выводим количество слагаемых в разложении.
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++) printf("%ld ", res[i]);
		printf("\n");
	}
	return 0;
}
