#include <iostream>

using namespace std;

int main() {
	long i, n, m, res;
	scanf("%ld %ld", &n, &m);
	//Если m ≤ n, то ответ равен 0.
	if (n >= m) res = 0;
	else
	{
		//Иначе n < m ≤ 2009, вычисляем значение n! mod m при помощи цикла.
		for (res = i = 1; i <= n; i++) res = (res * i) % m;
	}
	printf("%ld\n", res);
	return 0;
}
