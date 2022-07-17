#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include"binarytree.h"

// 前置声明
struct BinaryTree;

typedef struct BinaryTree* STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;//容量
}ST;
//初始化
void StackInit(ST* ps);
//销毁栈
void StackDestory(ST* ps);
//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//取值
STDataType StackTop(ST* ps);
//计算个数
int StackSize(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);