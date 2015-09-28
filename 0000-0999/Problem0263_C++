#include <iostream>
using namespace std;

long long  N, Sum_a, Sum_b, End1_a, End1_b, End11_a, End11_b;

int main()
{
	cin >> N;
	if (N == 1) cout << "2\n";
	else if (N == 2) cout << "4\n";
	else
	{
		Sum_a = 2;
		End1_a = 1;
		End11_a = 0;
		for (long long i = 2; i != N + 1; i++)
		{
			Sum_b = Sum_a * 2 - End11_a + 12345;
			End1_b = Sum_a - End1_a - End11_a + 12345;
			End11_b = End1_a + 12345;
			Sum_a = Sum_b % 12345;
			End1_a = End1_b % 12345;
			End11_a = End11_b % 12345;
		}
		cout << Sum_a << endl;
	}
}
