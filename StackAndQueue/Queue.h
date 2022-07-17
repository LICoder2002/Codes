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
//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestory(Queue* pq);
//��ͷ��
void QueuePush(Queue* pq, QDataType x);
//��β��
void QueuePop(Queue* pq);
//ȡ��ͷ��Ԫ��
QDataType QueueFront(Queue* pq);
//ȡ��β��Ԫ��
QDataType QueueBack(Queue* pq);
//����Ԫ�ظ���
int QueueSize(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

