#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Ҫ�󣺴洢�����ݴ�0��ʼ�����������洢
// ��̬��˳���
// ���⣺��С�ˣ������á������ˣ������˷ѡ�
//#define N 10000
//struct SeqList
//{
//	int a[N];
//	int size; // ��¼�洢�˶��ٸ�����
//};

typedef int SLDataType;

// ��̬��˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;     // �洢���ݸ���
	int capacity; // �洢�ռ��С
}SL, SeqList;

void SeqListPrint(SeqList* psl);

//void SLInit(SeqList* psl);
void SeqListInit(SeqList* psl);
void SeqListDestroy(SeqList* psl);

void SeqListCheckCapacity(SeqList* psl);

// ʱ�临�Ӷ���O(1)
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);

// ʱ�临�Ӷ���O(N)
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

// ��posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
// ɾ��posλ�õ�����
void SeqListErase(SeqList* psl, size_t pos);

// ˳������
int SeqListFind(SeqList* psl, SLDataType x);