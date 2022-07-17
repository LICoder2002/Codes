#include"SList.h"

void SListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
//检查是否增容
void SListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 2 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}
//尾插
void SListPushBack(SL* ps, SQDataType x)
{
	/*SListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SListInsert(ps, ps->size, x);
}
//头插
void SListPushFront(SL* ps, SQDataType x)
{
	SListCheckCapacity(ps);
	int end = ps->size - 1;
	while(end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
	//SListInsert(ps, 0, x);
}
//尾删
void SListPopBack(SL* ps);
//头删
void SListPopFront(SL* ps);
//pos 前插入x
void SListInsert(SL* ps, int pos, SQDataType x)
{
	assert(pos <= ps->size);
	SListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
//销毁pos处的元素
void SListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int cur = pos + 1;
	while (cur<ps->size)
	{
		ps->a[cur - 1] = ps->a[cur];
		cur++;
	}
	ps->size--;
}
//查找
int SListFind(SL* ps, SQDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}
//修改
void SListModity(SL* ps, int pos, SQDataType x)
{
	assert(pos <= ps->size - 1);
	ps->a[pos] = x;
}


