#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef int SQDataType;
typedef struct SList 
{
	SQDataType* a;
	int size;//Ԫ�ظ���
	int capacity;//����
}SL;
//��ʼ��
void SListInit(SL* ps);
//��ӡ
void SListPrint(SL* ps);
//����˳���
void SListDestory(SL* ps);
//����Ƿ�����
void SListCheckCapacity(SL* ps);
//β��
void SListPushBack(SL* ps, SQDataType x);
//ͷ��
void SListPushFront(SL* ps, SQDataType x);
//βɾ
void SListPopBack(SL* ps);
//ͷɾ
void SListPopFront(SL* ps);
//pos ǰ����x
void SListInsert(SL* ps, int pos, SQDataType x);
//����pos����Ԫ��
void SListErase(SL* ps, int pos);
//����
int SListFind(SL* ps, SQDataType x);
//�޸�
void SListModity(SL* ps, int pos, SQDataType x);


