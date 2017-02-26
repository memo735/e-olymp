#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long m, n, x, y;
	scanf("%ld %ld %ld %ld", &m, &n, &x, &y);
	//Заносим в переменную s количество клеток, которое бьет ферзь горизонтальными и вертикальными ходами.
	long s = m - 1 + n - 1; // horiz & vertical
	//Добавляем диагональные клетки, находящиеся под ударом.
	s += min(m - x, n - y); // (x,y) = (m, n)
	s += min(m - x, y - 1); // (x,y) = (m, 1)
	s += min(x - 1, n - y); // (x,y) = (1, n)
	s += min(x - 1, y - 1); // (x,y) = (1, 1)
	printf("%ld\n", s);
	return 0;
}
