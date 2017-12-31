#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define MAX 82000

vector<vector<int> > v;

int sum(int n)
{
	int s = 0;
	while (n > 0)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	int n;
	//Занесем в v[s] числа от 1 до 82000 с суммой цифр s. В процессе построения
	//списка смежности массивы v[s] уже являются отсортированными по возрастанию.
	v.resize(MAX);
	for (int i = 1; i < MAX; i++)
	{
		const int s = sum(i);
		v[s].push_back(i);
	}
	//Читаем входное значение n. Для каждого массива v[i], содержащего хотя бы n чисел, 
	//находим сумму n наименьших чисел.Среди всех таких сумм находим минимальную.
	scanf("%d", &n);
	long long res = 1e18;
	for (int i = 1; i < MAX; i++)
		if (v[i].size() >= n)
			res = min(res, accumulate(v[i].begin(), v[i].begin() + n, 0LL));
	printf("%lld\n", res);
	return 0;
}
