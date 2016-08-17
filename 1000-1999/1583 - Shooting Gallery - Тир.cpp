#include <iostream>

using namespace std;

int profitableBet(int accuracy)
{
	double miss = 1 - accuracy / 100.0, prob = miss;
	int n = 0;
	while (prob > 0.5) n++, prob *= miss;
	return n;
}

int main() {
	int acc;
	while (scanf("%d", &acc) == 1) printf("%d\n", profitableBet(acc));
	return 0;
}
