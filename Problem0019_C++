#include <stdio.h>

int main()
{
	int len = 0, answer = 0;
	char ch[12],temp;
	do
	{
		scanf("%c",&temp);
		if (temp != '\n') { ch[len] = temp; len++; }
	}
	while (temp != '\n');
	for (int i = 0; i<= (len - 1) / 2; i++) if (ch[i] == ch[len-i-1]) answer++;
	printf("%d\n",answer);
}
