#include <iostream>

int main()
{
	int n, arr[100];
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
