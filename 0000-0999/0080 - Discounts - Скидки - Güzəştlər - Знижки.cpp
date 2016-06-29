#include <iostream>

using namespace std;
int main()
{
	int n, m[10000], temp;
	long long Sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (m[i] < m[j])
			{
				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
	for (int i = 0; i < n - n % 3; i++) if ((i + 1) % 3) Sum += m[i];
	for (int i = n - n % 3; i < n; i++) Sum += m[i];
	cout << Sum << endl;
}
