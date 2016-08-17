#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int lower, upper, first, n, opponents[100];
double res[100];

double sqr(double x) { return x*x; }

double f(double low, double up, double z)
{
	if (z <= 2 * low) return 0.0;
	if (z <= low + up) return sqr(z - 2 * low) / (2 * sqr(up - low));
	if (z <= 2 * up) return 1 - sqr(z - 2 * up) / (2 * sqr(up - low));
	return 1.0;
}

//Искомые вероятности заносим в массив res.Отдельно вычисляем значения res[0] и res[n].
void getProbabilities(int low, int up, int first)
{
	for (int i = 0; i < n; i++) opponents[i] -= first;
	sort(opponents, opponents + n, greater<int>());
	res[0] = 1 - f(low, up, opponents[0]);
	res[n] = f(low, up, opponents[n - 1]);
	for (int i = 1; i < n; i++)
		res[i] = f(low, up, opponents[i - 1]) - f(low, up, opponents[i]);
}

int main() {
	while (scanf("%d %d %d %d", &lower, &upper, &first, &n) == 4)
	{
		for (int i = 0; i < n; i++) scanf("%d", &opponents[i]);
		getProbabilities(lower, upper, first);
		for (int i = 0; i < n + 1; i++) printf("%.4lf ", res[i]); printf("\n");
	}
	return 0;
}
