#include <iostream>

using namespace std;

//Функция find(n, k) находит число, которое находится
//в k - ой позиции последовательности кодов Грея длины n.
int find(int n, int k)
{
	if (!n) return 0;
	int temp = 1 << (n - 1);
	if (k < temp) return find(n - 1, k);
	return temp + find(n - 1, (1 << n) - 1 - k);
}

int main() {
	int n, k, res, tests;
	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d %d", &n, &k);
		res = find(n, k);
		printf("%d\n", res);
	}
	return 0;
}
