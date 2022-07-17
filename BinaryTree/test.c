#include"binarytree.h"
#include"queue.h"
#include"stack.h"


void test01()
{
	//BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	//InitBiTree(root);
	//root = CreateBiTree(root);
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	Non_R_InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	LevelOrder(A);

	printf("%d\n", Depth(A));
	printf("%d\n", NodeCount(A));
	printf("%d\n",LeafNodeCount(A));
}

int main()
{
	test01();

	system("pause");
	return 0;
}


