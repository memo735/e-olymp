#include <iostream>

using namespace std;
int a, b, c, d, tmp, index;

int main()
{
	cin >> a >> b >> c >> d;
	tmp = d;
	index = 1;
	while (tmp > a / b)
	{
		tmp -= a / b;
		index++;
	}
	cout << index << " ";
	tmp = d;
	index = 1;
	while (d > a / (b*c))
	{
		d -= a / (b*c);
		index++;
		if (index == c + 1) index = 1;
	}
	cout << index << endl;
}
