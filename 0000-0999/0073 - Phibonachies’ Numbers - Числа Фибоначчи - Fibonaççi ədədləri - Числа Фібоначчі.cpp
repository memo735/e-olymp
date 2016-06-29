#include <iostream>
#include <vector>

using namespace std;

int a[10], b[10];

bool check()
{
	for (long j = 0; j < 10; j++) if (b[j] > a[j]) return false;
	return true;
}

string SUM(string a, string b)
{
	for (int j = 0; j < a.length() / 2; j++) swap(a[j], a[a.length() - j - 1]);
	for (int j = 0; j < b.length() / 2; j++) swap(b[j], b[b.length() - j - 1]);
	if (a.length() < b.length()) swap(a, b);
	int j, ost = 0;
	for (j = 0; j < b.length(); j++)
	{
		ost += a[j] + b[j] - 96;
		a[j] = ost % 10 + 48;
		ost /= 10;
	}
	while (ost)
	{
		if (j == a.length()) a += ost + 48, ost = 0;
		else
		{
			ost += a[j] - 48;
			a[j] = ost % 10 + 48;
			ost /= 10;
			j++;
		}
	}
	for (int i = 0; i < a.length() / 2; i++) swap(a[i], a[a.length() - i - 1]);
	return a;
}

int main()
{
	int ans = -1, index = 2, sumA = 0;
	string A = "1", B = "1", C;
	for (int i = 0; i < 10; i++) { cin >> a[i]; sumA += a[i]; }
	while (B.length() <= sumA)
	{
		for (int i = 0; i < 10; i++) b[i] = 0;
		for (int i = 0; i < B.length(); i++) b[B[i] - 48]++;
		if (check()) ans = index;
		index++;
		C = SUM(A, B); A = B; B = C;
	}
	cout << ans << endl;
}
