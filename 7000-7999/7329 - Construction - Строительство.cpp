#include <iostream>

using namespace std;

int i, n, m, a[10001];

//Функция cnt возвращает количество досок, которое можно вырезать 
//из имеющихся, длины которых будут равны в точности Mid.
int cnt(int  Mid)
{
	if (Mid == 0) return 1e9;
	int res = 0;
	for (i = 0; i < n; i++) res += a[i] / Mid;
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	//Устанавливаем границы значения d и запускаем бинарный поиск.
	int Left = 0, Right = 1e9;
	while (Right - Left > 1)
	{
		const int Mid = (Left + Right) / 2;
		//Если из имеющихся можно вырезать хотя бы m досок, то 
		//передвигаем левый конец Left.Иначе двигаем правый Right.
		if (cnt(Mid) >= m) Left = Mid;
		else Right = Mid;
	}
	printf("%d\n", Left);
	return 0;
}
