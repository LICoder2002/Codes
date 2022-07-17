#include"DList.h"

void test()
{
	LN* DList = ListInit();
	ListPushFront(DList, 4);
	ListPushFront(DList, 3);
	ListPushFront(DList, 2);
	ListPushFront(DList, 1);
	ListPushFront(DList, 0);
	ListPrint(DList);
	ListPushBack(DList, 5);
	ListPushBack(DList, 6);
	ListPushBack(DList, 7);
	ListPushBack(DList, 8);
	ListPushBack(DList, 9);
	ListPrint(DList);
	ListPopBack(DList);
	ListPrint(DList);
	ListPopFront(DList);
	ListPrint(DList);
	printf("元素个数为：%d\n", ListSize(DList));
	ListDestory(DList);
}
int main()
{
	test();
	return 0;
}