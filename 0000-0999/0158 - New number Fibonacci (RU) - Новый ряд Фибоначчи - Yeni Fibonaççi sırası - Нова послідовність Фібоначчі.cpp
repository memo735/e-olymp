#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, tmp, i;
string d[7200];
bool db[7200];

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
	for (j = 0; j < a.length() / 2; j++) swap(a[j], a[a.length() - j - 1]);
	return a;
}

string dp(int fibo)
{
	if (db[fibo]) return d[fibo];
	db[fibo] = true;
	return d[fibo] = SUM(SUM(dp(fibo - 1), dp(fibo - 2)), SUM(dp(fibo - 3), dp(fibo - 4)));
}

int main()
{
	d[0] = d[1] = d[2] = d[3] = d[4] = "1";
	db[0] = db[1] = db[2] = db[3] = db[4] = true;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		cout << dp(tmp) << endl;
	}
}
