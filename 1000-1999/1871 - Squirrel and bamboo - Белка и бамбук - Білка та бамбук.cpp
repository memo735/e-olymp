#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> s;
int n, val;

int main() {
	scanf("%d", &n);
	s.push(0);
	while (n--)
	{
		scanf("%d", &val);
		if (val > 0) s.push(max(val, s.top()));
		else
		{
			s.pop();
			printf("%d\n", s.top());
		}
	}
	return 0;
}
