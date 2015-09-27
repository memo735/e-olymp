#include <iostream>

using namespace std;

int main()
{
	int temp, len = 0;
	unsigned char res[100];
	do
	{
		cin >> temp;
		if (temp)
		{
			res[len] = 1;
			while (!(temp % 2)) (res[len] *= 2, temp /= 2);
			len++;
		}
	} while (temp);
	for (int i = 0; i < len; i++) cout << (int)res[i] << endl;
}
