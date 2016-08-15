#include <iostream>
#include <string.h>
#include <set>

using namespace std;

set<string> SetS;
set<string>::iterator iter;
char s[201];

int main() {
	//Поскольку текст не обязательно начинается с буквы латинского
	//алфавита, то пропустим начальные символы, не являющиеся буквами.
	scanf("%[^a-zA-Z]", s);

	//Читаем слово, состоящее только из заглавных и прописных букв латинского алфавита
	//в переменную s, заменяем все буквы на маленькие и заносим слово во множество SetS.
	//Пропускаем все символы, не являющиеся буквами, читая их в массив s.
	while (scanf("%[a-zA-Z]", s) == 1)
	{
		for (int i = 0; i < strlen(s); i++) s[i] = tolower(s[i]);
		SetS.insert(s);
		scanf("%[^a-zA-Z]", s);
	}
	for (iter = SetS.begin(); iter != SetS.end(); ++iter) printf("%s\n", (*iter).c_str());
	return 0;
}
