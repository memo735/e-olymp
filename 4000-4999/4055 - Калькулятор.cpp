#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main()
{
	int n, qSize, index;
	pair <int, int> que[720001];
	vector <int> vect;
	cin >> n;
	que[0] = make_pair(n, 0);
	index = 0; qSize = 1;
	while (que[index].first != 1)
	{
		if (que[index].first % 2 == 0) que[qSize++] = make_pair(que[index].first / 2, index);
		if (que[index].first % 3 == 0) que[qSize++] = make_pair(que[index].first / 3, index);
		if (que[index].first % 3 < 2 || que[index].first % 2) que[qSize++] = make_pair(que[index].first - 1, index);
		index++;
	}
	while (index)
	{
		vect.push_back(que[index].first);
		index = que[index].second;
	}
	vect.push_back(n);
	sort(vect.begin(), vect.end());
	cout << vect.size() - 1 << endl << vect[0];
	for (int i = 1; i < vect.size(); i++) cout << " " << vect[i];
	cout << endl;
	return 0;
}
