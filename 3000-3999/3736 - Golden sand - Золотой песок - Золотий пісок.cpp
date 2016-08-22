#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int i, n;
	double w, vi, wi, res = 0.0;
	vector<pair<double, double>> v;
	scanf("%d %lf", &n, &w);
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf", &vi, &wi);
		v.push_back(make_pair(vi / wi, wi));
	}
	//Сортируем ящики по невозрастанию стоимости единицы песка.
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	//Грузим жадно рюкзак. Вес песка, который еще можно загрузить в рюкзак, равен w.
	//Берем i-ый ящик. В рюкзак можно положить вес не более min(w, вес i-го ящика).
	for (i = 0; i < v.size(); i++)
	{
		res += min(w, v[i].second) * v[i].first;
		w -= min(w, v[i].second);
	}
	printf("%.3lf\n", res);
	return 0;
}
