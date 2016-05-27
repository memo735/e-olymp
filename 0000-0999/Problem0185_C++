#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 1001

int countWords(char* speech)
{
	int wordCount = 0;
	char delim[] = " ,.!?:;-\"\'";
	char* pointer = strtok(speech, delim);
	while (pointer != NULL)
	{
		pointer = strtok(NULL, delim);
		wordCount++;
	}
	return wordCount;
}

int countSyllables(char* speech)
{
	int syllableCount = 0;
	char vowels[] = "aoeuAOEU";
	char* pointer = strpbrk(speech, vowels);
	while (pointer != NULL)
	{
		pointer = strpbrk(pointer + 1, vowels);
		syllableCount++;
	}
	return syllableCount;
}

int main()
{
	int n; cin >> n;
	char speech[SIZE];
	int words[n];
	int syllables[n];
	cin.ignore(); //пропустить перевод строки между числом и первой речью
	for (int i = 0; i < n; i++)
	{
		cin.getline(speech, SIZE);
		syllables[i] = countSyllables(speech);
		words[i] = countWords(speech);
	}
	bool many = false;
	int winner = 0;
	for (int i = 1; i < n; i++)
	{
		if (syllables[i] * words[winner] < syllables[winner] * words[i])
		{
			winner = i;
			many = false;
		}
		else if (syllables[i] * words[winner] == syllables[winner] * words[i])
		{
			if (words[winner] < words[i])
			{
				winner = i;
				many = false;
			}
			else if (words[winner] == words[i]) many = true;
		}
	}
	if (many) cout << "O-o-o-rks...";
	else cout << winner + 1 << endl;
	return 0;
}
