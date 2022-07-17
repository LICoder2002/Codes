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

	// Խ�粻һ���ܼ�������Խ���ǳ��
	// �����Ƽ�һ������һ���ᱻ�鵽����������һ�����ܾƼ�
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
	printf("1.β������ 2.ͷ������\n");
	printf("5.��ӡ���� 6.��������\n");
	printf("-1.�˳� \n");
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
		printf("��ѡ����Ĳ���:>");
		scanf_s("%d", &option);
		if (option == 1)
		{
			printf("��������Ҫβ�������:>");
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