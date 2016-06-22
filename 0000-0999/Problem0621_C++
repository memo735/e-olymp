#include <iostream>
#include <string>

using namespace std;

long A, B;
string s, ans;

bool ch()
{
	for (int i = 0; i < s.length(); i++) if (s[i] != '9') return false;
	cout << 1;
	for (int i = 0; i < s.length() - 1; i++) cout << 0;
	cout << 1 << endl;
	return true;
}

int main()
{
	cin >> s;
	A = 0; B = 0;
	if (ch()) return 0;
	for (int i = s.length() / 2 - 1; i >= 0; i--) A = A * 10 + s[i] - 48;
	for (int i = (s.length() + 1) / 2; i < s.length(); i++) B = B * 10 + s[i] - 48;
	if (s.length() % 2 && s[s.length() / 2] != '9' && A <= B)
	{
		for (int i = 0; i < s.length() / 2; i++) cout << s[i];
		cout << (char)(s[s.length() / 2] + 1);
		for (int i = s.length() / 2 - 1; i >= 0; i--) cout << s[i];
		cout << endl;
		return 0;
	}
	if (B >= A)
	{
		A++;
		long ost = 1;
		for (int i = s.length() / 2 - 1; i >= 0; i--)
		{
			ost += s[i] - 48;
			ans += ost % 10 + 48;
			ost /= 10;
		}
		if (s.length() % 2) s[s.length() / 2] = '0';
	}
	else
	{
		ans = "";
		while (A)
		{
			ans += A % 10 + 48;
			A /= 10;
		}
		for (int i = 0; i < ans.length() / 2; i++) swap(ans[i], ans[ans.length() - i - 1]);
	}
	for (int i = ans.length() - 1; i >= 0; i--) cout << ans[i];
	if (s.length() % 2) cout << s[s.length() / 2];
	cout << ans << endl;
	return 0;
}
