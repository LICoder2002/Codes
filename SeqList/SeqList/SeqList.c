#include "SeqList.h"

void SeqListPrint(SeqList* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SeqListDestroy(SeqList* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}

void SeqListCheckCapacity(SeqList* psl)
{
	assert(psl);

	// 如果满了，我们要扩容
	if (psl->size == psl->capacity)
	{
		size_t newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = realloc(psl->a, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			psl->a = tmp;
			psl->capacity = newCapacity;
		}
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	/*SeqListCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;*/

	SeqListInsert(psl, psl->size, x);
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	//psl->a[psl->size - 1] = 0;
	/*if (psl->size > 0)
	{
		psl->size--;
	}*/
	SeqListErase(psl, psl->size - 1);
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	//SeqListCheckCapacity(psl);

	//// 挪动数据，腾出头部空间
	//int end = psl->size - 1;
	//while (end >= 0)
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	--end;
	//}

	//psl->a[0] = x;
	//psl->size++;

	SeqListInsert(psl, 0, x);
}

void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	// 挪动数据覆盖删除
	/*if (psl->size > 0)
	{
		int begin = 1;
		while (begin < psl->size)
		{
			psl->a[begin - 1] = psl->a[begin];
			++begin;
		}

		--psl->size;
	}*/
	SeqListErase(psl, 0);
}

// 在pos位置插入x
//void SeqListInsert(SeqList* psl, int pos, SLDataType x)
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	// 暴力检查
	assert(psl);

	// 温和检查
	if (pos > psl->size)
	{
		printf("pos 越界：%d\n", pos);
		return;
		//exit(-1);
	}
	// 暴力检查
	//assert(pos <= psl->size);

	SeqListCheckCapacity(psl);

	//int end = psl->size - 1;
	//while (end >= (int)pos)
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	--end;
	//}

	size_t end = psl->size;
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}

	psl->a[pos] = x;
	psl->size++;
}

// 删除pos位置的数据
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);

	size_t begin = pos + 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}

	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}