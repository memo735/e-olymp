#include <iostream>

using namespace std;

long long n, tmp, answer;

int main()
{
	cin >> n;
	tmp = 5;
	while (tmp < n)
	{
		answer += n / tmp;
		tmp *= 5;
	}
	cout << answer << endl;
}
