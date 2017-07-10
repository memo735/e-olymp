#include <iostream>
#include <string.h>

using namespace std;

const int M = 500000;

int idx, TopOrder[M], Child[M + 1][2];
char State[M + 1];
bool Seen[M + 1];
long Visits[M + 1];

void topsort(int i)
{
	if (Seen[i]) return;
	Seen[i] = true;
	topsort(Child[i][0]);
	topsort(Child[i][1]);
	TopOrder[--idx] = i;
}

int main()
{
	int m, i;
	long n;
	scanf("%ld %d\n", &n, &m);
	for (i = 1; i <= m; i++) scanf("%c %d %d\n", &State[i], &Child[i][0], &Child[i][1]);
	memset(Seen, false, sizeof Seen);
	Seen[0] = true;
	idx = m;
	topsort(1);
	memset(Visits, 0, sizeof Visits);
	Visits[1] = n;
	for (int j = idx; j < m; j++)
	{
		i = TopOrder[j];
		long v = Visits[i];
		int k = (State[i] == 'L' ? 0 : 1);
		Visits[Child[i][k]] += (v + 1) / 2;
		Visits[Child[i][1 - k]] += v / 2;
		if (v & 1) State[i] = (k ? 'L' : 'R');
	}
	for (i = 1; i <= m; i++) printf("%c", State[i]);
	printf("\n");
	return 0;
}
