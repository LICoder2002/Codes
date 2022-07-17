#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef int SQDataType;
typedef struct SList 
{
	SQDataType* a;
	int size;//元素个数
	int capacity;//容量
}SL;
//初始化
void SListInit(SL* ps);
//打印
void SListPrint(SL* ps);
//销毁顺序表
void SListDestory(SL* ps);
//检查是否增容
void SListCheckCapacity(SL* ps);
//尾插
void SListPushBack(SL* ps, SQDataType x);
//头插
void SListPushFront(SL* ps, SQDataType x);
//尾删
void SListPopBack(SL* ps);
//头删
void SListPopFront(SL* ps);
//pos 前插入x
void SListInsert(SL* ps, int pos, SQDataType x);
//销毁pos处的元素
void SListErase(SL* ps, int pos);
//查找
int SListFind(SL* ps, SQDataType x);
//修改
void SListModity(SL* ps, int pos, SQDataType x);


