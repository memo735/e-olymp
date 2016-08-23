#include <iostream>
#include <algorithm>

using namespace std;

class Stack {
public:
	Stack(int size);
	void push(int x);
	void pop();
	int getMin() const;
private:
	int* m, size;
};

Stack::Stack(int size = 1000001) {
	m = new int[size];
	this->size = 0;
}

void Stack::push(int x) {
	if (size == 0) m[size++] = x;
	else
	{
		int pos = size - 1;
		m[size++] = min(x, m[pos]);
	}
}

void Stack::pop() { size--; }

int Stack::getMin() const { return m[size - 1]; }


int n, x, op;
int main() {
	//Моделируем работу стека.
	Stack s;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &x);
			s.push(x);
		}
		else
			if (op == 2) s.pop();
			else printf("%d\n", s.getMin());
	}
	return 0;
}
