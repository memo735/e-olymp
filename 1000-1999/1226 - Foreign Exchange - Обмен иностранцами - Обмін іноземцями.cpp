#include <iostream>
#include <set>

using namespace std;

multiset<pair<int, int> > s;
multiset<pair<int, int> >::iterator iter;

int main() {
	int a, b, i, n, t;
	scanf("%d", &t);

	//После чтения количества студентов n очищаем мультимножество s.
	//Для каждой входной пары (А, В) проверяем, есть ли в мультимножестве пара (В, А).
	//Если есть – то удаляем (В, А), иначе – вставляем(А, В).
	while (t--)
	{
		scanf("%d", &n); s.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			if ((iter = s.find(make_pair(b, a))) == s.end()) s.insert(make_pair(a, b));
			else s.erase(iter);
		}
		//Если в конце работы мультимножество s пусто, то у каждой пары (А, В) существует
		//соответствующая ей пара(В, А) и обмен студентами может быть успешно произведен.
		if (s.empty()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
