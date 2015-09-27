#include <iostream>
#include <string> 

using namespace std;

string str;
char tmp;
int length, ost;

void swap()
{
	length = str.length();
	for (int i = 0; i < length / 2; i++)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
	}
}

int main()
{
	cin >> str;
	swap();
	ost = 1;
	for (int i = 0; i < length; i++)
	{
		ost = ost + (str[i] - 48);
		str[i] = (ost % 10) + 48;
		ost /= 10;
	}
	if (ost) str += "1";
	swap();
	cout << str << endl;
}
