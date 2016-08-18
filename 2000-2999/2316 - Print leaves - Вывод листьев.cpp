#include <iostream>
#include <algorithm>

using namespace std;

int n, flag;

struct TreeNode
{
	int data;
	TreeNode *left, *right;
	TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
//Объявим указатель tree на дерево.
TreeNode *tree;

//Вставка числа n в дерево tree. Если число n в дереве уже существует, то ничего не добавляем.
void insert(TreeNode *&tree, int n)
{
	if (!tree)
	{
		tree = new TreeNode(n);
		return;
	}
	if (tree->data == n) return;
	if (n < tree->data) insert(tree->left, n);
	else insert(tree->right, n);
}

//Совершим рекурсивный обход дерева слева направо. Выводим все листы в порядке обхода.
void InOrder(TreeNode *tree)
{
	if (!tree) return;
	InOrder(tree->left);
	if (tree->left == NULL && tree->right == NULL)
	{
		if (flag) printf(" ");
		printf("%d", tree->data);
		flag = 1;
	}
	InOrder(tree->right);
}

int main() {
	//Читаем входные данные, строим дерево.
	while (scanf("%d", &n), n) insert(tree, n);
	InOrder(tree);
	printf("\n");
	return 0;
}
