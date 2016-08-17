#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<long> H;
char s[1000001];
long d, i, j, n, p, len, hash1;

int main() {

	while (scanf("%d ", &n) == 1)
	{
		gets(s);
		len = strlen(s);
		H.clear();

		//Вычисляем хеш hash1 префикса строки s длины n. Заносим его в массив H.Установим p = 27^(n - 1).
		for (p = 1, hash1 = i = 0; i < n; i++, p *= 27) hash1 = hash1 * 27 + (s[i] - 'a' + 1);
		p /= 27; H.push_back(hash1);

		//Вычисляем хеши всех подстрок длины n. Заносим их в массив H.
		for (i = 0; i < len - n; i++)
		{
			hash1 %= p;
			hash1 = hash1 * 27 + s[i + n] - 'a' + 1;
			H.push_back(hash1);
		}
		sort(H.begin(), H.end());

		//Ищем хеш hash1, который чаще всего встречается в массиве H.
		for (d = i = 0; i < H.size(); i = j)
		{
			for (j = i; j < H.size() && H[j] == H[i]; j++);
			if (j - i > d) d = j - i, hash1 = H[i];
		}
		while (hash1) printf("%c", hash1 / p + 'a' - 1), hash1 %= p, p /= 27;
		printf("\n");
	}
	return 0;
}
