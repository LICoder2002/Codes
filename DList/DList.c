#include"DList.h"

//初始化
LN* ListInit()
{
	LN* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//创建结点
LN* BuyListNode(DataType x)
{
	LN* newnode = (LN*)malloc(sizeof(LN));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->prev = NULL;
		newnode->next = NULL;
		return newnode;
	}
}
//销毁链表
void ListDestory(LN* phead)
{
	assert(phead);
	LN* cur = phead->next;
	while (cur != phead)
	{
		LN* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
//打印链表
void ListPrint(LN* phead)
{
	assert(phead);
	LN* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//头插
void ListPushFront(LN* phead, DataType x)
{
	assert(phead);
	LN* newnode = BuyListNode(x);
	LN* first = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}
//尾插
void ListPushBack(LN* phead, DataType x)
{
	assert(phead);
	LN* tail = phead->prev;
	LN* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}
//头删
void ListPopFront(LN* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LN* first = phead->next;

	phead->next = first->next;
	first->next->prev = phead;
	free(first);
	first = NULL;
}
//尾删
void ListPopBack(LN* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LN* tail = phead->prev;

	//phead->prev = tail->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;
}
//查找x并返回x结点位置
LN* ListFind(LN* phead, DataType x)
{
	assert(phead);
	LN* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//在pos前插入x
void ListInsert(LN* pos, DataType x)
{
	assert(pos);
	LN* newnode = BuyListNode(x);

	LN* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除pos处的元素
void ListErase(LN* pos)
{
	assert(pos);
	LN* prev = pos->prev;
	LN* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}
//判断链表是否为空
bool ListEmpty(LN* phead)
{
	if (phead == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//计算元素个数
int ListSize(LN* phead)
{
	int size = 0;
	assert(phead);
	LN* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}