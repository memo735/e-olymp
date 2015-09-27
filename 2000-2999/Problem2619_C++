#include <iostream>

using namespace std;

long n, Sum = 0, tmp = 0;
unsigned char mas[1000000], ch;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		Sum += mas[i] - 48;
	}
	for (int i = 0; i < n; i++)
	{
		tmp += mas[i] - 48;
		if (tmp * 2 == Sum)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
