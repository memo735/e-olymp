#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A = "1", B; cin >> B;
	int n = 1;
	for (int i = 0; i < B.length() / 2; i++) swap(B[i], B[B.length() - i - 1]);;
	if (B == "1") cout << 1 << endl;
	else
	{
		while (A != B)
		{
			n++;
			int ost = 0;
			for (int i = 0; i < A.length(); i++)
			{
				ost += (A[i] - 48) * n;
				A[i] = ost % 10 + 48;
				ost /= 10;
			}
			while (ost)
			{
				A += ost % 10 + 48;
				ost /= 10;
			}
		}
		cout << n << endl;
	}
}
