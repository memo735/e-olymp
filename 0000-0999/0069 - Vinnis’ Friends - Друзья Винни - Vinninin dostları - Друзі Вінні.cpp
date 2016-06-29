#include <iostream>
using namespace std;
int n, m, h, N[1000], M[1000], answer = 0;

bool check()
{
	if (h == n) for (int i = 0; i < h; i++) if (N[i] != M[i]) return false;
	if (h != n) return false;
	return true;
}

int main()
{
	for (int i = 0; i < 1000; i++) { N[i] = 0; M[i] = 0; }
	cin >> m >> n; h = m;
	for (int i = 0; i < m; i++) cin >> M[i];
	for (int i = 0; i < n; i++) cin >> N[i];
	while (!check())
	{
		for (int i = 1; M[0]; i++)
		{
			if (!M[i]) h++;
			M[0]--;
			M[i]++;
		}
		for (int i = 1; i < h; i++) M[i - 1] = M[i];
		M[h - 1] = 0;
		h--;
		answer++;
	}
	cout << answer << endl;
}
