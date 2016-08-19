#include <iostream>
#include <algorithm>

using namespace std;

int n, x[50];

//Процедура генерации разбиений Partitions имеет три аргумента: pos – текущая позиция в массиве x,
//max – максимально возможное слагаемое, которое может находиться в позиции pos, number – число, которое разбивается.
void Partitions(int pos, int max, int number)
{
	int i;
	if (!number)
	{
		//Если разбиваемое число number равно нулю, то выводим текущее разбиение, построенное в массиве x.
		printf("%d", x[0]);
		for (i = 1; i < pos; i++) printf(" %d", x[i]);
		printf("\n");
	}
	else //В позиции pos массива x может находиться любое число от 1 до min(max, number).
		for (i = 1; i <= min(max, number); i++)
		{
			x[pos] = i;
			Partitions(pos + 1, i, number - i);
		}
}

int main() {
	//Читаем входное значение n и запускаем генерацию всех разбиений.
	scanf("%d", &n);
	Partitions(0, n, n);
	return 0;
}
