#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, i = 2, mas[100];
	cin >> n; int l = 2; int k = 0;
	for (int j = 2; j <= n; j++)
	{
		i = j; while (l <= i)
		{
			if (i%l == 0)
			{
				mas[k++] = l;
				i = i / l;
			}
			else l++;
		}
		l = 2;
	}
	int z = 0, count = 1, mas1[100];
	sort(mas, mas + k);
	for (i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++) if (mas[j] == mas[i]) count++;
		mas1[z] = count;
		i = i + count - 1;
		z++;
		count = 1;
	}
	int result = 1;
	for (i = 0; i < z; i++) result = (mas1[i] + 1)*result;
	cout << result << endl; return 0;
}
