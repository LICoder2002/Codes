#include "SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 0);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 20);
	SeqListPrint(&s);

	//SeqListPrint(NULL);

	// 越界不一定能检查出来，越界是抽查
	// 就像查酒驾一样。不一定会被查到，但是我们一定不能酒驾
	//int a[10];
	//a[10] = 1;
	//a[11] = 1;
	//a[12] = 1;
	//a[100] = 1;
}

void TestSeqList2()
{
	/*int* p = (int*)malloc(sizeof(int) * 10);
	printf("%p\n", p);

	int* p1 = (int*)realloc(p, sizeof(int) * 100);
	printf("%p\n", p1);*/

	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);
}

void TestSeqList3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	SeqListInsert(&s, 10, 100);
	SeqListInsert(&s, 1, 20);
	SeqListInsert(&s, 5, 50);
	SeqListInsert(&s, 0, 50);

	SeqListPrint(&s);

	SeqListDestroy(&s);
}

void TestSeqList4()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListErase(&s, 4);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListPrint(&s);
}

void TestSeqList5()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
}

void menu()
{
	printf("***********************************************\n");
	printf("1.尾插数据 2.头插数据\n");
	printf("5.打印数据 6.查找数据\n");
	printf("-1.退出 \n");
	printf("***********************************************\n");
}

int main()
{
	//TestSeqList5();
	SeqList s;
	SeqListInit(&s);
	int option = -1;
	do
	{
		menu();
		printf("请选择你的操作:>");
		scanf_s("%d", &option);
		if (option == 1)
		{
			printf("请输入你要尾插的数据:>");
			//int val = 0;
			SLDataType val = 0;
			scanf_s("%d", &val);
			SeqListPushBack(&s, val);
		}
		else if (option == 5)
		{
			SeqListPrint(&s);
		}
	} while (option != -1);

	SeqListDestroy(&s);

	return 0;
}