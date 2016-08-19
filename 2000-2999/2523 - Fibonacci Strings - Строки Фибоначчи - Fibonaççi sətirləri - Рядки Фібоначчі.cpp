#include <iostream>

using namespace std;

#define MAX 41

int n, m, l, fib[MAX] = { 0, 1 };

string solve(int n, int Left, int Right)
{
	if (n == 1) return "b";
	if (n == 2) return "a";
	if (Right <= fib[n - 1]) return solve(n - 1, Left, Right);
	if (Left > fib[n - 1]) return solve(n - 2, Left - fib[n - 1], Right - fib[n - 1]);
	return solve(n - 1, Left, fib[n - 1]) + solve(n - 2, 1, Right - fib[n - 1]);
}

int main() {
	for (int i = 2; i < MAX; i++) fib[i] = fib[i - 1] + fib[i - 2];
	scanf("%d %d %d", &n, &m, &l);
	string res = solve(n, m, m + l - 1);
	puts(res.c_str());
	return 0;
}
