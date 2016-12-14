#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

//Функция f(n) вычисляет количество супернатуральных чисел,
//произведение цифр которых равно n, и запоминает его в m[n].
int f(int n)
{
	int res = 0;
	if (m[n]) return m[n];
	for (int i = 2; i <= 9; i++)
		if (n % i == 0) res = (res + f(n / i)) % 101;
	return m[n] = res;
}

int main() {
	int n, res;
	scanf("%d", &n);
	m[1] = 1;
	res = n == 1 ? 0 : f(n);
	printf("%d\n", res);
	return 0;
}
