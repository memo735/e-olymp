#include <iostream>
#include <string>

using namespace std;

string str;
int length, n = 1, mas[1024], lenmas = 1, sum = 1, ost;

int main()
{
	cin >> str;
	length = str.length();
	mas[0] = 2;
	while (sum < length)
	{
		ost = 0;
		for (int i = 0; i < lenmas; i++)
		{
			ost += mas[i] * 2;
			mas[i] = ost % 10;
			ost /= 10;
		}
		while (ost)
		{
			mas[(lenmas++)] = ost % 10;
			ost /= 10;
		}
		n++;
		sum += lenmas;
	}
	cout << n << endl;
}
