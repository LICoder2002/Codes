#include "Heap.h"

// 假设指定树的度
//#define N 5
//struct TreeNode
//{
//	int data;
//	struct TreeNode* subs[N];  // 指针数组
//};

// 不知道树的度
//struct TreeNode
//{
//	int data;
//	// 顺序表存孩子的指针
//	//SeqList _sl; // SLDateType -> struct TreeNode*
//	// vector<struct TreeNode*> _subs; C++
//};

//// 孩子兄弟表示法
//typedef int DataType;
//struct TreeNode
//{
//	struct TreeNode* firstChild;    // 第一个孩子结点
//	struct TreeNode* pNextBrother;  // 指向其下一个兄弟结点
//	DataType data;                  // 结点中的数据域
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

// 升序 O(N*logN)   1000*10    100w*20
//      O(N*N)      1000*1000  100w*100w
// O(N)空间复杂度，还需要再优化--下节课再来讲解
// 升序
//void HeapSort(int* a, int size)
//{
//	// 小堆
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

// 优化
// 要求：时间复杂度O(N*logN)
//       空间复杂度O(1)
// 升序
void HeapSort(int* a, int n)
{
	// 向上调整--建堆 O(N*logN)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

	// 向下调整--建堆 O(N)
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
	// 1. 建堆--用a中前k个元素建堆
	int* kminHeap = (int*)malloc(sizeof(int) * k);
	assert(kminHeap);

	for (int i = 0; i < k; ++i)
	{
		kminHeap[i] = a[i];
	}

	// 建小堆
	for (int j = (k - 1 - 1) / 2; j >= 0; --j)
	{
		AdjustDown(kminHeap, k, j);
	}

	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
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