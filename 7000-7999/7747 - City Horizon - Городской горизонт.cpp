#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

struct Node
{
	int x, flag, h;
	Node(int x, int flag, int h) : x(x), flag(flag), h(h) {}
	int operator< (const Node &a) const { return x < a.x; }
};

//Объявим массив точек Event, а также мультимножество s для хранения высот
//прямоугольников, пересекающихся с текущей абсциссой сканирующей прямой.
vector<Node> Event;
multiset<int, greater<int> > s;

int main() {
	int i, n, left, right, height;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &left, &right, &height);
		Event.push_back(Node(left, 0, height));
		Event.push_back(Node(right, 1, height));
	}
	//Сортируем массив точек по неубыванию абсцисс.
	sort(Event.begin(), Event.end());
	//Двигаемся слева направо по точкам массива Event.
	long res = 0, last = 0;
	for (i = 0; i < 2 * n; i++)
	{
		int x = Event[i].x, type = Event[i].flag, h = Event[i].h;
		if (!s.empty()) res += 1L * *s.begin() * (x - last);
		//Если точка xi – начало здания, то соответствующую ей высоту добавим в мультимножество.
		if (type == 0) s.insert(h);
		//Если точка xi  – конец здания, то удалим из мультимножества соответствующую ей высоту.
		else s.erase(s.find(h));
		//Предыдущей абсциссой объявим текущую.
		last = x;
	}
	printf("%ld\n", res);
	return 0;
}
