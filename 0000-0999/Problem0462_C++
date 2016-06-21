#include <iostream>

using namespace std;

int main()
{
	int mas[100], n, tmp; cin >> n;
	for (int i = 0; i < n; i++) cin >> mas[i];
	int k; cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		mas[tmp - 1]--;
	}
	for (int i = 0; i < n; i++)
		if (mas[i] >= 0) cout << "no" << endl;
		else cout << "yes" << endl;
}
