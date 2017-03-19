#include <iostream> 

using namespace std;

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		cout << 2 * (n + m) << " " << n*m << endl;
	}
}
