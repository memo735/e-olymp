#include <iostream>
#include <string.h>

using namespace std;

#define MAX 50

long res, salary[MAX];
char rel[MAX][MAX];
int i, n;

//Поиск в глубину из вершины i. Если  зарплата i-го работника уже подсчитана (salary[i] ≠ 0), то
//завершаем поиск. Иначе запускаем поиск в глубину со всех сыновей вершины i, вычисляем зарплаты
//всех подчиненных i - го работника.Зарплата i - го работника равна сумме зарплат всех его подчиненных.
long dfs(int i)
{
	int j;
	long &res = salary[i];
	if (salary[i] > 0) return salary[i];
	for (res = j = 0; j < n; j++)
		if (rel[i][j] == 'Y') res += dfs(j);
	if (!res) res = 1;
	return res;
}

int main() {
	//Читаем в массив rel матрицу смежности графа.
	while (scanf("%d\n", &n) == 1)
	{
		for (i = 0; i < n; i++) gets(rel[i]);
		memset(salary, 0, sizeof salary);

		//Запускаем поиск в глубину на ориентированном графе. Находим зарплату каждого работника.
		for (i = 0; i < n; i++) if (!salary[i]) dfs(i);

		//Вычисляем и выводим суммарную зарплату всех работников res.
		for (res = i = 0; i < n; i++) res += salary[i];
		printf("%ld\n", res);
	}
	return 0;
}
