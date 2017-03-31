#include <iostream>

using namespace std;

int main() {
	int t, t1;
	scanf("%d %d", &t, &t1);
	//Второй поезд прибудет в конечный пункт через t2 / t1 часов или через
	//tm = 60 * t2 / t1 минут. Представим это время в виде h часов m минут.
	int tm = 60 * t * t / t1;
	printf("%d %d\n", tm / 60, tm % 60);
	return 0;
}
