#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;
//˫������
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	DataType data;
}LN;
//��ʼ��
LN* ListInit();
//�������
LN* BuyListNode(DataType x);
//��������
void ListDestory(LN* phead);
//��ӡ����
void ListPrint(LN* phead);
//ͷ��
void ListPushFront(LN* phead, DataType x);
//β��
void ListPushBack(LN* phead, DataType x);
//ͷɾ
void ListPopFront(LN* phead);
//βɾ
void ListPopBack(LN* phead);
//����x������x���λ��
LN* ListFind(LN* phead, DataType x);
//��posǰ����x
void ListInsert(LN* pos, DataType x);
//ɾ��pos����Ԫ��
void ListErase(LN* pos);
//�ж������Ƿ�Ϊ��
bool ListEmpty(LN* phead);
//����Ԫ�ظ���
int ListSize(LN* phead);
