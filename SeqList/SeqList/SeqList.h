#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 要求：存储的数据从0开始，依次连续存储
// 静态的顺序表
// 问题：开小了，不够用。开大了，存在浪费。
//#define N 10000
//struct SeqList
//{
//	int a[N];
//	int size; // 记录存储了多少个数据
//};

typedef int SLDataType;

// 动态的顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;     // 存储数据个数
	int capacity; // 存储空间大小
}SL, SeqList;

void SeqListPrint(SeqList* psl);

//void SLInit(SeqList* psl);
void SeqListInit(SeqList* psl);
void SeqListDestroy(SeqList* psl);

void SeqListCheckCapacity(SeqList* psl);

// 时间复杂度是O(1)
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);

// 时间复杂度是O(N)
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

// 在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
// 删除pos位置的数据
void SeqListErase(SeqList* psl, size_t pos);

// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x);