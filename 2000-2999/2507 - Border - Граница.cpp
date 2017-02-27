#include <iostream>

using namespace std;

char s[101][101];
int i, j, w, h, res;

int main() {
	scanf("%d %d\n", &w, &h);
	for (i = 0; i < h; i++) gets(s[i]);
	//Считаем длину вертикальных границ.
	for (i = 0; i < h; i++)
		for (j = 0; j < w - 1; j++)
			if (s[i][j] != s[i][j + 1]) res++;

	//Считаем длину горизонтальных границ.
	for (i = 0; i < h - 1; i++)
		for (j = 0; j < w; j++)
			if (s[i][j] != s[i + 1][j]) res++;

	printf("%d\n", res);
	return 0;
}
