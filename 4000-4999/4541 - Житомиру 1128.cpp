#include <iostream>
#include <string.h>

using namespace std;

long long mas[10], n, price, answer = 0, tmp;

int main()
{
	cin >> n >> price;
	memset(mas, 0, 10);
	tmp = n;
	while (tmp)
	{
		mas[tmp % 10]++;
		tmp /= 10;
	}
	tmp = n + 1;
	while (tmp)
	{
		mas[tmp % 10]--;
		tmp /= 10;
	}
	for (int i = 0; i < 10; i++)
		if (mas[i] < 0) answer += abs(mas[i]) * price;
	cout << answer << endl;
	return 0;
}
