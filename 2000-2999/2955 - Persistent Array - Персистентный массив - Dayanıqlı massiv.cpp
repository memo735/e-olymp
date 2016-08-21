#include <iostream>

using namespace std;

#define MAX 100001

int i, n, m, pos, ptr, ver, value, a[MAX];
char q[3];

struct SegmentTree
{
	int value;
	struct SegmentTree *Left, *Right;
} *PSTree[MAX];

//Создание дерева отрезков V из элементов a[L..R].
void build(SegmentTree &V, int *a, int L, int R)
{
	if (L == R)
	{
		V.value = a[L];
		V.Left = V.Right = NULL;
		return;
	}
	int Mid = (L + R) / 2;
	V.Left = new SegmentTree();
	build(*V.Left, a, L, Mid);
	V.Right = new SegmentTree();
	build(*V.Right, a, Mid + 1, R);
}

//В дереве отрезков V совершим изменение a[pos] = value.
void Update(SegmentTree &V, int L, int R, int pos, int value)
{
	if (L == R)
	{
		V.value = value;
		return;
	}
	int Mid = (L + R) / 2;
	if (pos <= Mid)
	{
		SegmentTree *Left = new SegmentTree();
		*Left = *V.Left;
		V.Left = Left;
		Update(*Left, L, Mid, pos, value);
	}
	else
	{
		SegmentTree *Right = new SegmentTree();
		*Right = *V.Right;
		V.Right = Right;
		Update(*Right, Mid + 1, R, pos, value);
	}
}

//В дереве отрезков V возвратим значение a[pos].
int Get(SegmentTree &V, int L, int R, int pos)
{
	if (L == R) return V.value;
	int Mid = (L + R) / 2;
	if (pos <= Mid) return Get(*V.Left, L, Mid, pos);
	return Get(*V.Right, Mid + 1, R, pos);
}

int main() {
	//Читаем входные данные.
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	//Сохраняем входной массив в виде дерева отрезков в PSTree[0].
	PSTree[0] = new SegmentTree();
	build(*PSTree[0], a, 0, n);

	//Последовательно обрабатываем m запросов.
	scanf("%d", &m); ptr = 1;
	while (m--)
	{
		scanf("%s", q);
		if (q[0] == 'c')
		{
			//Обработка операции create.
			scanf("%d %d %d", &ver, &pos, &value);
			SegmentTree *node = new SegmentTree();
			*node = *PSTree[ver - 1];
			PSTree[ptr] = node;
			Update(*PSTree[ptr++], 0, n, pos, value);
		}
		else
		{
			//Обработка операции get.
			scanf("%d %d %d", &ver, &pos);
			printf("%d\n", Get(*PSTree[ver - 1], 0, n, pos));
		}
	}
	return 0;
}
