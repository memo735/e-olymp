#include <iostream>

using namespace std;

int main()
{
	int n, Max, count_max = 1, tmp;
	cin >> n >> Max;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		if (tmp > Max)
		{
			Max = tmp;
			count_max = 1;
		}
		else if (tmp == Max) count_max++;
	}
	cout << count_max << endl;
}
