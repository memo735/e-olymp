#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int i, n;
vector<int> j(3, 0);
vector<vector<int> > jobs;

//Функция сортировки.Сравнение a[0]/b[0] < a[1]/b[1] эквивалентно a[0]*b[1] < b[0]*a[1].
//Если отношения a[0]//b[0] и a[1]//b[1] равны, то раньше должна следовать работа с меньшим номером.
//Поэтому в этом случае следует сравнивать номера работ, которые содержатся в a[2] и b[2].
int lt(vector<int> a, vector<int> b)
{
	if (a[0] * b[1] == b[0] * a[1]) return a[2] < b[2];
	return a[0] * b[1] < b[0] * a[1];
}

int main() {
	while (scanf("%d", &n) == 1)
	{
		jobs.clear();
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &j[0], &j[1]);
			j[2] = i;
			jobs.push_back(j);
		}
		sort(jobs.begin(), jobs.end(), lt);
		printf("%d", jobs[0][2]);
		for (i = 1; i < n; i++) printf(" %d", jobs[i][2]);
		printf("\n");
	}
	return 0;
}
