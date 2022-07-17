#include"DList.h"

//��ʼ��
LN* ListInit()
{
	LN* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//�������
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
//��������
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
//��ӡ����
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
//ͷ��
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
//β��
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
//ͷɾ
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
//βɾ
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
//����x������x���λ��
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
//��posǰ����x
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
//ɾ��pos����Ԫ��
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
//�ж������Ƿ�Ϊ��
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
//����Ԫ�ظ���
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