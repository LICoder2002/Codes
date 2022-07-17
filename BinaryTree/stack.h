#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include"binarytree.h"

// ǰ������
struct BinaryTree;

typedef struct BinaryTree* STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;//����
}ST;
//��ʼ��
void StackInit(ST* ps);
//����ջ
void StackDestory(ST* ps);
//��ջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//ȡֵ
STDataType StackTop(ST* ps);
//�������
int StackSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);