#include <iostream>

using namespace std;

int CountSix(int n)
{
	int c = 0;
	while (n > 0)
	{
		c += n % 10 == 6;
		n /= 10;
	}
	return c;
}

//Вычисляем f(n) – количество шестерок в последовательных натуральных числах от 1 до n.
int f(int n)
{
	if (n < 10) return n >= 6;
	int res = 0;
	while (n % 10 != 9) res += CountSix(n--);
	return res + (n + 1) / 10 + f(n / 10) * 10;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > b) swap(a, b);
	printf("%d\n", f(b) - f(a - 1));
	return 0;
}
