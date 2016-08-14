#include <iostream>
#include <set>

using namespace std;

set<pair<int, int> > s;
int k, p, code;

int main() {
	//В зависимости от типа запроса производим соответствующее действие.
	//Продолжаем цикл, пока система обслуживания клиентов не остановится (значение code не станет равным 0).
	while (scanf("%d", &code), code)
		//Заносим приоритет и номер поступившего клиента во множество s.
		if (code == 1)
		{
			scanf("%d %d", &k, &p);
			s.insert(make_pair(p, k));
		}
		else //Наибольший приоритет клиента находится в конце множества s.
			if (code == 2)
				if (s.empty()) printf("0\n");
				else
				{
					auto iter = s.end();
					--iter;
					printf("%d\n", (*iter).second);
					s.erase(iter);
				}
			else //Наименьший приоритет клиента находится в начале множества s.
				if (s.empty()) printf("0\n");
				else
				{
					printf("%d\n", (*s.begin()).second);
					s.erase(s.begin());
				}
	return 0;
}
