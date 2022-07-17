#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;
//双向链表
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	DataType data;
}LN;
//初始化
LN* ListInit();
//创建结点
LN* BuyListNode(DataType x);
//销毁链表
void ListDestory(LN* phead);
//打印链表
void ListPrint(LN* phead);
//头插
void ListPushFront(LN* phead, DataType x);
//尾插
void ListPushBack(LN* phead, DataType x);
//头删
void ListPopFront(LN* phead);
//尾删
void ListPopBack(LN* phead);
//查找x并返回x结点位置
LN* ListFind(LN* phead, DataType x);
//在pos前插入x
void ListInsert(LN* pos, DataType x);
//删除pos处的元素
void ListErase(LN* pos);
//判断链表是否为空
bool ListEmpty(LN* phead);
//计算元素个数
int ListSize(LN* phead);
