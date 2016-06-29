#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, tmp1, tmp2, count_len;
float ans;
bool bv[100];
vector< pair<int, int> > v;
vector< pair<float, pair<int, int> > > len;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
	}
	if (n == 1) { cout << 0 << endl; return 0; }
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			len.push_back(make_pair(hypot(v[i].first - v[j].first, v[i].second - v[j].second), make_pair(i, j)));

	sort(len.begin(), len.end());
	bv[len[0].second.first] = true;
	for (int i = 0; i < len.size(); i++)
	{
		if (count_len == n - 1) break;
		if (bv[len[i].second.first] ^ bv[len[i].second.second])
		{
			ans += len[i].first;
			bv[len[i].second.first] = bv[len[i].second.second] = true;
			i = 0;
		}
	}
	if (ans - int(ans) >= 0.5) ans += 1;
	cout << int(ans) << endl;
}
