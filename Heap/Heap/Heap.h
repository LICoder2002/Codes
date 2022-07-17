#pragma once

// С��
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	size_t size;
	size_t capacity;
}HP;

void AdjustUp(HPDataType* a, size_t child);
void AdjustDown(HPDataType* a, size_t size, size_t root);

void Swap(HPDataType* pa, HPDataType* pb);
//void HeapInitArray(HP* php, HPDataType* a, size_t n);
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPrint(HP* php);

// ����x�Ժ󣬱�����������(��/С)��
// O(logN)
void HeapPush(HP* php, HPDataType x);

// ɾ���Ѷ������ݡ�(��С/���)
void HeapPop(HP* php);
bool HeapEmpty(HP* php);
size_t HeapSize(HP* php);
HPDataType HeapTop(HP* php);
