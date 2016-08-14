#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int x, Height;
	Node(int x, int Height) : x(x), Height(Height) {};
};

stack<Node> s;

int main() {
	//Считаем высоты нулевого и(n + 1) - го прямоугольника равными нулю. Занесем в стек нулевой прямоугольник.
	int h, n, i;
	long res;
	scanf("%d", &n);
	s.push(Node(0, 0));

	//Последовательно обрабатываем прямоугольники.
	for (res = 0, i = 1; i <= n + 1; i++)
	{
		//Читаем высоту i - го прямоугольника. Если i = n + 1, то высота равна нулю. Его абсцисса x равна i.
		if (i <= n) scanf("%d", &h);
		else h = 0;
		int x = i;
		while (h < s.top().Height)
		{
			x = s.top().x;
			int Height = s.top().Height;
			s.pop();
			long area = 1L * Height * (i - x);
			if (area > res) res = area;
		}
		if (h > s.top().Height) s.push(Node(x, h));
	}
	printf("%ld\n", res);
	return 0;
}
