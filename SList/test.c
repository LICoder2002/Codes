#include"SList.h"

void test()
{
	SL sl;
	SListInit(&sl);
	printf("β�壺\n");
	SListPushBack(&sl, 5);
	SListPrint(&sl);
	SListPushBack(&sl, 6);
	SListPrint(&sl);
	SListPushBack(&sl, 7);
	SListPrint(&sl);
	SListPushBack(&sl, 8);
	SListPrint(&sl);
	SListPushBack(&sl, 9);
	SListPrint(&sl);
	printf("ͷ��:\n");
	SListPushFront(&sl, 4);
	SListPrint(&sl);
	SListPushFront(&sl, 3);
	SListPrint(&sl);
	SListPushFront(&sl, 2);
	SListPrint(&sl);
	SListPushFront(&sl, 1);
	SListPrint(&sl);
	SListPushFront(&sl, 0);
	SListPrint(&sl);
	printf("���±�Ϊ2��λ��ǰ����10:\n");
	SListInsert(&sl, 2, 10);
	SListPrint(&sl);
	printf("ɾ���±�Ϊ2��Ԫ��:\n");
	SListErase(&sl, 2, 10);
	SListPrint(&sl);
	int index = SListFind(&sl, 2);
	printf("��2���±꣺\n");
	printf("�ҵ�2���±�Ϊ:%d\n", index);
	printf("���±�Ϊ2��Ԫ�ظ�Ϊ10\n");
	SListModity(&sl, 2, 100);
	SListPrint(&sl);
	printf("���±�Ϊ2��Ԫ�ظ�Ϊ2:\n");
	SListModity(&sl, 2, 2);
	SListPrint(&sl);

}

int main()
{
	test();
	return 0;
}