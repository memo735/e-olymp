#include <stdio.h>

class Point
{
public:
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	void Read() { scanf("%d %d", &x, &y); }
	void Print() const { printf("%d %d\n", x, y); }

	Point operator +(const Point &a) const { return {x + a.x, y + a.y}; }
	Point operator +(int value) const { return {x + value, y + value}; }
};

int main()
{
	Point a, b;
	a.Read(); b.Read();
	int n;
	scanf("%d", &n);
	(a + b + n).Print();
	return 0;
}
