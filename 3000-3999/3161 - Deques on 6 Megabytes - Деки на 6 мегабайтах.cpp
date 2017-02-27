#include <iostream>
#include <string.h>
#include <map>

using namespace std;

class deque
{
	struct node
	{
		int data;
		node *next, *prev;
		node() { prev = next = nullptr; }
		node(int a)
		{
			data = a;
			prev = next = nullptr;
		}
	} *Head, *Tail;

public:
	deque() { Head = Tail = nullptr; }
	void push_back(int a)
	{
		node *p = new node(a);
		if (Head == nullptr) Head = Tail = p;
		else
		{
			p->prev = Tail;
			p->next = nullptr;
			Tail->next = p;
			Tail = p;
		}
	}

	void push_front(int a)
	{
		node *p = new node(a);
		if (Head == nullptr) Head = Tail = p;
		else
		{
			p->next = Head;
			p->prev = nullptr;
			Head->prev = p;
			Head = p;
		}
	}

	int pop_front()
	{
		node *p = Head;
		int r = Head->data;
		if (Head == Tail) Head = Tail = nullptr;
		else
		{
			Head = Head->next;
			Head->prev = nullptr;
		}
		delete p;
		return r;
	}

	int pop_back()
	{
		node *p = Tail;
		int r = Tail->data;
		if (Head == Tail) Head = Tail = nullptr;
		else
		{
			Tail = Tail->prev;
			Tail->next = nullptr;
		}
		delete p;
		return r;
	}

	int empty() const { return Head == nullptr; }

	int front() const { return Head->data; }

	int back() const { return Tail->data; }
};

deque q[150001];

int main() {
	int a, b, n;
	char s[100];
	scanf("%d\n", &n);
	while (n--)
	{
		scanf("%s %d", s, &a);
		if (!strcmp(s, "pushback"))
		{
			scanf("%d\n", &b);
			q[a].push_back(b);
		}
		if (!strcmp(s, "pushfront"))
		{
			scanf("%d\n", &b);
			q[a].push_front(b);
		}
		if (!strcmp(s, "popfront"))
		{
			scanf("\n");
			printf("%d\n", q[a].front());
			q[a].pop_front();
		}
		if (!strcmp(s, "popback"))
		{
			scanf("\n");
			printf("%d\n", q[a].back());
			q[a].pop_back();
		}
	}
	return 0;
}
