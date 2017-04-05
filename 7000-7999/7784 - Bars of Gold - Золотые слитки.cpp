#include <iostream>

using namespace std;

int main() {
	int a, b, c, mid;
	scanf("%d %d %d", &a, &b, &c);
	mid = (a + b + c) / 2;
	//Проверяем, можно ли разделить золото без разрезаний.
	if (a + b == mid || a + c == mid || b + c == mid) puts("0");
	else
	{
		//Если надо резать первый кусок.
		if (mid < a) printf("1\n%d %d\n", mid, a - mid);
		else
		{
			//Если надо резать второй кусок.
			if (mid < a + b) printf("2\n%d %d\n", mid - a, a + b - mid);
			//Если надо резать третий кусок.
			else printf("3\n%d %d\n", mid - a - b, mid);
		}
	}
	return 0;
}
