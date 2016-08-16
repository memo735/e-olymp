#include <iostream>

using namespace std;

char ch;
int a, res;

int main() {
	scanf("%d", &res);
	//Если следующий за очередным числом символ является знаком операции (сложения или вычитания),
	//то читаем следующее число a и прибавляем его к или вычитаем его из общего результата.

	while (scanf("%c", &ch), ch != '\n')
	{
		scanf("%d", &a);
		if (ch == '+') res += a;
		else res -= a;
	}
	printf("%d\n", res);
	return 0;
}
