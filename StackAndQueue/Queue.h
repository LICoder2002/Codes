#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;
//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//队头入
void QueuePush(Queue* pq, QDataType x);
//队尾出
void QueuePop(Queue* pq);
//取队头的元素
QDataType QueueFront(Queue* pq);
//取对尾的元素
QDataType QueueBack(Queue* pq);
//计算元素个数
int QueueSize(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);

