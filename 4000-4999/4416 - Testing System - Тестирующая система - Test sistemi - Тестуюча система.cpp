#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, i, ptr;

struct person
{
	int id, penalty_time, problems;
};

vector<person> acm;

int cmp(person a, person b)
{
	if (a.problems != b.problems) return a.problems > b.problems;
	if (a.penalty_time != b.penalty_time) return a.penalty_time < b.penalty_time;
	return a.id < b.id;
}

int main()
{
	scanf("%d", &n);
	acm.resize(n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &acm[i].problems, &acm[i].penalty_time);
		acm[i].id = i + 1;
	}
	sort(acm.begin(), acm.end(), cmp);
	for (i = 0; i < n; i++) printf("%d ", acm[i].id);
	printf("\n");
	return 0;
}
