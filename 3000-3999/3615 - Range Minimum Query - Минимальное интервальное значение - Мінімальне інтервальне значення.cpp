#include <iostream>

using namespace std;

#define MAX 2000000000

//Структура вершины Item имеет следующий вид.Приоритет будем устанавливать рандомизировано.
struct Item
{
	int cnt, x, Min, Priority;
	Item *l, *r;
	Item() { }
	Item(int x) : x(x), Min(x), Priority((rand() << 16u) + unsigned(rand())), l(NULL), r(NULL) { }
};

typedef Item* Pitem;
Pitem t, t1, t2;

int min(int x, int y) { return x < y ? x : y; }

int cnt(Pitem t) { return t ? t->cnt : 0; }

int GetMin(Pitem t) { return t ? t->Min : MAX; }

void upd(Pitem t)
{
	if (t)
	{
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
		t->Min = min(t->x, min(GetMin(t->l), GetMin(t->r)));
	}
}

//Слияние деревьев l и r в t.
void Merge(Pitem l, Pitem r, Pitem &t)
{
	if (!l || !r) t = l ? l : r;
	else if (l->Priority > r->Priority) Merge(l->r, r, l->r), t = l;
	else Merge(l, r->l, r->l), t = r;
	upd(t);
}

//В дерево l заносится pos вершин дерева t, в дерево r все остальные.
void Split(Pitem t, Pitem &l, Pitem &r, int pos)
{
	if (!t) return void(l = r = nullptr);
	if (pos <= cnt(t->l)) Split(t->l, l, t->l, pos), r = t;
	else Split(t->r, t->r, r, pos - 1 - cnt(t->l)), l = t;
	upd(t);
}

int main() {
	//Последовательно обрабатываем запросы.
	int i, j, n, k;
	char c;
	scanf("%d\n", &n);
	for (k = 0; k < n; k++)
	{
		scanf("%c %d %d\n", &c, &i, &j);
		if (c == '+')
		{
			Split(t, t1, t2, i);
			Merge(t1, new Item(j), t1);
			Merge(t1, t2, t);
		}
		else
		{
			Split(t, t, t1, i - 1);
			Split(t1, t1, t2, j - i + 1);

			//Разрезали исходное дерево на три : t, t1, t2. Выводим
			//минимум на дереве t1. После чего делаем склейку.
			printf("%d\n", t1->Min);
			Merge(t, t1, t);
			Merge(t, t2, t);
		}
	}
	return 0;
}
