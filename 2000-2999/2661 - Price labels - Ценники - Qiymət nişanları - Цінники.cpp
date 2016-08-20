#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n, val;

int main() {
	//Читаем входные данные. Заносим ценники как для первого
	//так и для второго супермаркета во множество s.
	scanf("%d", &n);
	while (n--) scanf("%d", &val), s.insert(val);
	scanf("%d", &n);
	while (n--) scanf("%d", &val), s.insert(val);

	//Выводим содержимое множества s.
	for (set<int>::iterator iter = s.begin(); iter != s.end();)
	{
		printf("%d", *iter++);
		if (iter != s.end()) printf(" ");
	}
	printf("\n");
	return 0;
}
