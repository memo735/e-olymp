#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<pair<long, char> > m(10);
vector<string> numbers;
int n, canzero[10];
char s[20];

long maximumSum()
{
	int i, j;
	long pow10, s;
	for (i = 0; i < 10; i++) m[i].first = 0, m[i].second = i + 'A', canzero[i] = 1;
	for (i = 0; i < numbers.size(); i++)
	{
		pow10 = 1;
		for (j = numbers[i].size() - 1; j >= 0; j--)
		{
			m[numbers[i][j] - 'A'].first += pow10;
			pow10 *= 10;
		}
		canzero[numbers[i][0] - 'A'] = 0;
	}
	sort(m.begin(), m.end());
	for (i = 0; !canzero[m[i].second - 'A']; i++);
	swap(m[0], m[i]);
	sort(m.begin() + 1, m.end());
	for (s = i = 0; i < 10; i++) s += m[i].first * i;
	return s;
}

int main() {
	while (scanf("%d\n", &n) == 1)
	{
		numbers.clear();
		for (int i = 0; i < n; i++)
		{
			gets(s),
			numbers.push_back(s);
		}
		printf("%ld\n", maximumSum());
	}
	return 0;
}
