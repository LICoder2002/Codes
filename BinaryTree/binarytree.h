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

//��ʼ��������
void InitBiTree(BTNode* root);

//����������
BTNode* CreateBiTree(BTNode* root);

//�������
void PrevOrder(BTNode* T);

//�������
void InOrder(BTNode* T);

//�ǵݹ��������
void Non_R_InOrder(BTNode* T);

//�������
void PostOrder(BTNode* T);

//�������
void LevelOrder(BTNode* T);

//����
void CopyBiTree(BTNode* T, BTNode* NewT);

//���
int Depth(BTNode* T);

//�ڵ���
int NodeCount(BTNode* T);

//Ҷ�ӽڵ���
int LeafNodeCount(BTNode* T);