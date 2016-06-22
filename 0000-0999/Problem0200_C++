#include <iostream>

using namespace std;

int main()
{
	pair<int, int> a, b, c, d;
	int AB, AC, AD, BC, BD, CD;
	bool x, y, z;
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
	AB = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
	AC = (a.first - c.first)*(a.first - c.first) + (a.second - c.second)*(a.second - c.second);
	AD = (a.first - d.first)*(a.first - d.first) + (a.second - d.second)*(a.second - d.second);
	BC = (b.first - c.first)*(b.first - c.first) + (b.second - c.second)*(b.second - c.second);
	BD = (b.first - d.first)*(b.first - d.first) + (b.second - d.second)*(b.second - d.second);
	CD = (c.first - d.first)*(c.first - d.first) + (c.second - d.second)*(c.second - d.second);
	x = AB == CD && AC == BC && BC == BD && BD == AD && AC + BC == AB;
	y = AC == BD && AB == BC && BC == CD && CD == AD && AB + BC == AC;
	z = AD == BC && AB == BD && BD == CD && CD == AC && AB + BD == AD;
	if (x || y || z) cout << "YES" << endl;
	else cout << "NO" << endl;
}
