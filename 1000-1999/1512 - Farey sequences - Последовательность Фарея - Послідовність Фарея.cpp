#include <iostream>

using namespace std;

bool flag;
int n, k;

void farey(int a1, int b1, int a2, int b2)
{
	if (n < b1 + b2) return;
	farey(a1, b1, a1 + a2, b1 + b2);
	if (flag) return;
	if (k == 1)
	{
		printf("%d/%d\n", a1 + a2, b1 + b2);
		flag = 1;
		return;
	}
	k--;
	farey(a1 + a2, b1 + b2, a2, b2);
}

int main() {
	//Генерируем все дроби из Fn, начиная с интервала(0 / 1, 1 / 1).
	//Как только будет сгенерирована k - ая дробь, выводим ее и останавливаем
	//дальнейший процесс генерации. Если по окончанию работы функции farey
	//flag = 0, то это означает, что k - ой дробью является 1 / 1.
	while (scanf("%d %d", &n, &k) == 2)
	{
		flag = 0; farey(0, 1, 1, 1);
		if (!flag) printf("1/1\n");
	}
	return 0;
}
