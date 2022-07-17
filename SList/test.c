#include"SList.h"

void test()
{
	SL sl;
	SListInit(&sl);
	printf("尾插：\n");
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
	printf("头插:\n");
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
	printf("在下标为2的位置前插入10:\n");
	SListInsert(&sl, 2, 10);
	SListPrint(&sl);
	printf("删除下标为2的元素:\n");
	SListErase(&sl, 2, 10);
	SListPrint(&sl);
	int index = SListFind(&sl, 2);
	printf("找2的下标：\n");
	printf("找到2的下标为:%d\n", index);
	printf("将下标为2的元素改为10\n");
	SListModity(&sl, 2, 100);
	SListPrint(&sl);
	printf("将下标为2的元素改为2:\n");
	SListModity(&sl, 2, 2);
	SListPrint(&sl);

}

int main()
{
	test();
	return 0;
}