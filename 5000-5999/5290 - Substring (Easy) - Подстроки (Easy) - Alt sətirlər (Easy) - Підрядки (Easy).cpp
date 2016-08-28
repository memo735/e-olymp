#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct node
{
	int next[26];
	node()
	{
		for (int i = 0; i < 26; i++) next[i] = 0;
	}
};

//Объявим бор. Сначала он состоит из одной вершины.
vector<node> trie(1);
int i, j, len, pos;
char s[101];

int main() {
	gets(s); len = strlen(s);

	//Заносим все суффиксы строки s в бор.
	for (i = 0; i < len; i++)
	{
		pos = 0;
		//Заносим в бор суффикс si si + 1 …slen - 1.
		for (j = i; j < len; j++)
		{
			char ch = s[j] - 'a';
			if (trie[pos].next[ch] == 0)
			{
				node temp;
				trie[pos].next[ch] = trie.size();
				trie.push_back(temp);
			}
			pos = trie[pos].next[ch];
		}
	}
	//Выводим количество разных подстрок. Оно на единицу меньше
	//числа вершин в боре (пустая подстрока не считается).
	printf("%llu\n", trie.size() - 1);
	return 0;
}
