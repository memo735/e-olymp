#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 1001

int d[MAX], fi[MAX];

//Заполняем массив fi[i].
void FillEuler()
{
	memset(fi, 0, sizeof fi); fi[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!fi[i]) {
			//Число i является простым.
			for (int j = i; j < MAX; j += i)
			{
				if (!fi[j]) fi[j] = j;
				fi[j] -= fi[j] / i;
			}
		}
	}
}

//Перед вызовом функции f значения d[i] уже содержит. Тело функции f
//добавляет в d[j] значения так, чтобы в конце работы функции d[j]
//содержало sum(i=1..j-1) GCD(i,j) согласно формуле, приведенной в теореме.
void f()
{
	for (int i = 2; i <= sqrt(1.0*MAX); i++)
		for (int j = i * i; j < MAX; j += i)
		{
			//Число i является делителем j. Поэтому в d[j] следует прибавить.
			//Поскольку делителем j также является число j / i, то в d[j] следует добавить (j/i)*fi[j/(j/i)]=(j/i)*fi[i].
			//Если i^2 = j, то к d[j] следует прибавлять не два слагаемых, а только одно i*fi[j/i]=i*fi[i].
			//Цикл по i достаточно продолжать до, так как если i – делитель j и i > sqrt(MAX), то с учетом того что
			//j / i < sqrt(MAX) можно утверждать, что делитель i числа j был уже учтен когда рассматривался делитель j / i.
			if (i * i < j) d[j] += i * fi[j / i] + j / i * fi[i];
			if (i * i == j) d[j] += i * fi[i]; // i = j / i
		}
}

int main() {
	memset(d, 0, sizeof d);
	FillEuler();
	for (int i = 2; i < MAX; i++) d[i] = fi[i];
	f();
	for (int i = 3; i < MAX; i++) d[i] += d[i - 1];
	int n;
	while (scanf("%d", &n), n) printf("%d\n", d[n]);
	return 0;
}
