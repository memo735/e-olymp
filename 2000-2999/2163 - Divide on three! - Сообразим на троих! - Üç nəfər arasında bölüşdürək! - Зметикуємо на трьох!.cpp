#include <iostream>

using namespace std;

int main() {
	char c;
	int s = 0;
	while (scanf("%c", &c), c != '\n') s += c - '0';
	printf(s % 3 == 0 ? "YES\n" : "NO\n");
	return 0;
}
