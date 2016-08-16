#include <iostream>
#include <math.h>

using namespace std;

#define MAX 100001

double res, logFact[MAX], ans[MAX];
int i, n;

int main() {
	//Занесем в logFact[i] значение ln i!.
	res = logFact[1] = 0.0;
	for (res = 0, i = 2; i < MAX; i++)
	{
		res += log(i);
		logFact[i] = res;
	}
	for (i = 2; i < MAX; i += 2)
	{
		res = logFact[i - 2] - 2 * logFact[i / 2 - 1] - (i - 2)*log(2.0);

		//Переменнмая res содержит ln(C(i/2-1, i-2)*p^(i/2-1)*q^(i/2-1)).
		//Заносим в ans[i]  значение C(i/2-1, i-2)*p^(i/2-1)*q^(i/2-1).
		ans[i] = exp(res);
	}
	while (scanf("%d", &n) == 1) printf("%.8lf\n", 1 - ans[n]);
	return 0;
}
