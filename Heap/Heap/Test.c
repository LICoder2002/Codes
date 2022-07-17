#include "Heap.h"

// ����ָ�����Ķ�
//#define N 5
//struct TreeNode
//{
//	int data;
//	struct TreeNode* subs[N];  // ָ������
//};

// ��֪�����Ķ�
//struct TreeNode
//{
//	int data;
//	// ˳���溢�ӵ�ָ��
//	//SeqList _sl; // SLDateType -> struct TreeNode*
//	// vector<struct TreeNode*> _subs; C++
//};

//// �����ֵܱ�ʾ��
//typedef int DataType;
//struct TreeNode
//{
//	struct TreeNode* firstChild;    // ��һ�����ӽ��
//	struct TreeNode* pNextBrother;  // ָ������һ���ֵܽ��
//	DataType data;                  // ����е�������
//};

void TestHeap()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 5);
	HeapPush(&hp, 0);
	HeapPush(&hp, 8);
	HeapPush(&hp, 3);
	HeapPush(&hp, 9);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

// ���� O(N*logN)   1000*10    100w*20
//      O(N*N)      1000*1000  100w*100w
// O(N)�ռ临�Ӷȣ�����Ҫ���Ż�--�½ڿ���������
// ����
//void HeapSort(int* a, int size)
//{
//	// С��
//	HP hp;
//	HeapInit(&hp);
//	// O(N*logN)
//	for (int i = 0; i < size; ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	// O(N*logN)
//	size_t j = 0;
//	while (!HeapEmpty(&hp))
//	{
//		a[j] = HeapTop(&hp);
//		j++;
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}

// �Ż�
// Ҫ��ʱ�临�Ӷ�O(N*logN)
//       �ռ临�Ӷ�O(1)
// ����
void HeapSort(int* a, int n)
{
	// ���ϵ���--���� O(N*logN)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

	// ���µ���--���� O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	size_t end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}
//
//int main()
//{
//	TestHeap();
//	//int a[] = { 4, 2, 7, 8, 5, 1, 0, 6 };
//	//HeapSort(a, sizeof(a) / sizeof(int));
//
//	//for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	//{
//	//	printf("%d ", a[i]);
//	//}
//	//printf("\n");
//
//	return 0;
//}

void PrintTopK(int* a, int n, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ���
	int* kminHeap = (int*)malloc(sizeof(int) * k);
	assert(kminHeap);

	for (int i = 0; i < k; ++i)
	{
		kminHeap[i] = a[i];
	}

	// ��С��
	for (int j = (k - 1 - 1) / 2; j >= 0; --j)
	{
		AdjustDown(kminHeap, k, j);
	}

	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
	for (int i = k; i < n; ++i)
	{
		if (a[i] > kminHeap[0])
		{
			kminHeap[0] = a[i];
			AdjustDown(kminHeap, k, 0);
		}
	}

	for (int j = 0; j < k; ++j)
	{
		printf("%d ", kminHeap[j]);
	}
	printf("\n");
	free(kminHeap);
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2305] = 1000000 + 6;
	a[99] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[0] = 1000000 + 1000;
	PrintTopK(a, n, 10);
}

int main()
{
	TestTopk();

	return 0;
}