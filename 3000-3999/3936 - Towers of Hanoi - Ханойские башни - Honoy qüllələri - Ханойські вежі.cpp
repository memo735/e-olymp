#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int additional)
{
	if (n == 0) return;
	hanoi(n - 1, from, additional, to);
	printf("%d %d\n", from, to);
	hanoi(n - 1, additional, to, from);
}

int main() {
	int n; cin >> n;
	hanoi(n, 1, 2, 3);
	return 0;
}
