#include <iostream>

using namespace std;

#define MINF -2000000000

int n, y;

struct item
{
	int Key, Priority;
	item *l, *r;
	item() { }
	item(int Key, int Priority) : Key(Key), Priority(Priority), l(NULL), r(NULL) { }
};

typedef item* pitem;
pitem L, R, Tree;

//Функцию split разрезания дерева t по ключу Key реализуем так,
//чтобы элемент дерева, равный ключу Key, отходил в правое поддерево r.
void split(pitem t, int Key, pitem &l, pitem &r)
{
	if (!t) l = r = NULL;
	else if (Key <= t->Key) split(t->l, Key, l, t->l), r = t;
	else split(t->r, Key, t->r, r), l = t;
}

//Функция merge сливает два декартовых дерева l и r в t.
void merge(pitem l, pitem r, pitem &t)
{
	if (!l || !r) t = l ? l : r;
	else if (l->Priority > r->Priority) merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
}

//Функция GetMin  возвращает минимальный ключ в дереве t.
int GetMin(pitem t)
{
	if (t == NULL) return -1;
	if (t->l == NULL) return t->Key;
	return GetMin(t->l);
}

//Реализация операции add. Если элемент с ключом i уже присутствует в дереве,
//то после разреза он будет минимальным в R. В таком случае (когда GetMin(R) равно i)
//ничего добавлять не надо, но следует склеить дерево Tree обратно.
//Иначе добавляем новый элемент с ключом i методом вклейки.
//Приоритет каждого нового элемента выбираем произвольно при помощи функции rand(),
//чтобы строящееся декартово дерево Tree было максимально сбалансировано.
void add(int i)
{
	split(Tree, i, L, R);
	if (GetMin(R) != i)
	{
		merge(L, new item(i, rand()), Tree);
		merge(Tree, R, Tree);
	}
	else merge(L, R, Tree);
}

//Реализация операции next. Разрезаем дерево Tree по ключу i. Выводим
//минимальный элемент правого полученного дерева R.Собираем дерево Tree обратно.
void next(int i)
{
	split(Tree, i, L, R);
	y = GetMin(R);
	printf("%d\n", y);
	merge(L, R, Tree);
}

int main() {
	//Переменную y устанавливаем в MINF = -2000000000, если предыдущим не был запрос “ ? ”.
	y = MINF;
	scanf("%d\n", &n);
	while (n--)
	{
		char c;
		int i;
		scanf("%c %d\n", &c, &i);
		if (c == '+')
		{
			if (y > MINF) i = (i + y) % 1000000000, y = MINF;
			add(i);
		}
		else next(i);
	}
	return 0;
}
