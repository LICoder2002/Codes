#include"binarytree.h"


//初始化二叉树
void InitBiTree(BTNode* root)
{
	root->data = "";
	root->left = root->right = NULL;
}

//创建二叉树
BTNode* CreateBiTree(BTNode* root)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		root = NULL;
	}
	else
	{
		if (!(root = malloc(sizeof(BTDataType))))
		{
			printf("malloc fail\n");
			exit(-1);
		}
		root->data = ch;
		root->left = CreateBiTree(root->left);//构造左树
		root->right = CreateBiTree(root->right);//构造右数
	}
	return root;
}

//创建二叉树
BTNode* CreateBiTree(BTNode* root);

//先序遍历
void PrevOrder(BTNode* T)
{
	if (T == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", T->data);
	PrevOrder(T->left);
	PrevOrder(T->right);
}

//中序遍历
void InOrder(BTNode* T)
{
	if (T == NULL)
	{
		printf("NULL ");

		return;
	}

	InOrder(T->left);
	printf("%c ", T->data);
	InOrder(T->right);
}

//非递归中序遍历
void Non_R_InOrder(BTNode* T)
{
	BTNode* p;
	p = T;
	ST st;
	StackInit(&st);
	while (p || !StackEmpty(&st))
	{
		if (p)
		{
			StackPush(&st, p);
			p = p->left;
		}
		else
		{
			BTNode* q = StackTop(&st);
			StackPop(&st);
			printf("%c ", q->data);
			p = q->right;
		}

	}

}

//后序遍历
void PostOrder(BTNode* T)
{
	if (T == NULL)
	{
		printf("NULL ");

		return;
	}

	PostOrder(T->left);
	PostOrder(T->right);
	printf("%c ", T->data);

}

//层序遍历
void LevelOrder(BTNode* root)
{
	// 核心思路：上一层出的时候带下一层节点进
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");

	QueueDestory(&q);
}


//复制
void CopyBiTree(BTNode* T, BTNode* NewT)
{
	if (T == NULL)
	{
		NewT = NULL;
		return;
	}
	else
	{
		NewT = (BTNode*)malloc(sizeof(BTNode));
		NewT->data = T->data;
		CopyBiTree(T->left, NewT->left);
		CopyBiTree(T->right, NewT->right);
	}
}

//深度
int Depth(BTNode* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int m = Depth(T->left);
		int n = Depth(T->right);
		if (m > n)
		{
			return m + 1;
		}
		else
		{
			return n + 1;
		}
	}
}

//节点数
int NodeCount(BTNode* T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		return NodeCount(T->left) + NodeCount(T->left) + 1;
	}
}

//叶子节点数
int LeafNodeCount(BTNode* T)
{
	if (T == NULL)
	{
		return 0;
	}
	if (T->left == NULL && T->right == NULL)
	{
		return 1;
	}
	else
	{
		return LeafNodeCount(T->left) + LeafNodeCount(T->right);
	}
}