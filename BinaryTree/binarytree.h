#pragma once
#include"queue.h"
#include"stack.h"

typedef char BTDataType;
typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;

	BTDataType data;
}BTNode;

//初始化二叉树
void InitBiTree(BTNode* root);

//创建二叉树
BTNode* CreateBiTree(BTNode* root);

//先序遍历
void PrevOrder(BTNode* T);

//中序遍历
void InOrder(BTNode* T);

//非递归中序遍历
void Non_R_InOrder(BTNode* T);

//后序遍历
void PostOrder(BTNode* T);

//层序遍历
void LevelOrder(BTNode* T);

//复制
void CopyBiTree(BTNode* T, BTNode* NewT);

//深度
int Depth(BTNode* T);

//节点数
int NodeCount(BTNode* T);

//叶子节点数
int LeafNodeCount(BTNode* T);