#include <stdio.h>

int main()
{
	unsigned char temp;
	long index = 10000;
	bool m[20000];
	for (int i = 0; i<20000; i++) m[i] = false;
	m[index] = true;
	do
	{
		scanf("%c", &temp);
		if (temp != '\n')
		{
			if (temp == 'L') m[++index] = true;
			if (temp == 'R') m[--index] = true;
		}
	} while (temp != '\n');
	index = 0;
	for (int i = 0; i<20000; i++) if (m[i]) index++;
	printf("%d\n", index);
}
