#include"sort.h"


void testInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	PrintArray(a, n);

}

void testBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	BubbleSort(a, n);
	PrintArray(a, n);
}

void testShellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	PrintArray(a, n);
}


void testQuickSort1()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort1(a, 0, n - 1);
	PrintArray(a, n);
}

void testQuickSort2()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort2(a, 0, n - 1);
	PrintArray(a, n);
}

void testQuickSort3()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort3(a, 0, n - 1);
	PrintArray(a, n);
}

void testHeapSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	PrintArray(a, n);
}

void testSelectSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	PrintArray(a, n);
}

void testMergeSort1()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort1(a, n);
	PrintArray(a, n);
}

void testMergeSort2()
{
	int a[] = { 9,1,2,5,7,4,8,6, 3, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort2(a, n);
	PrintArray(a, n);
}

void testCountSort()
{
	int a[] = { 9,1,2,5,7,4,8,6, 3, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	PrintArray(a, n);
}

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);
	int* a9 = (int*)malloc(sizeof(int) * N);
	int* a10 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
		a10[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort1(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort1(a6, N);
	int end6 = clock();

	int begin10 = clock();
	MergeSort2(a6, N);
	int end10 = clock();

	int begin7 = clock();
	BubbleSort(a7, N);
	int end7 = clock();

	int begin8 = clock();
	QuickSort2(a8, 0, N - 1);
	int end8 = clock();


	int begin9 = clock();
	QuickSort2(a9, 0, N - 1);
	int end9 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort1:%d\n", end5 - begin5);
	printf("QuickSort2:%d\n", end8 - begin8);
	printf("QuickSort3:%d\n", end9 - begin9);
	printf("MergeSort1:%d\n", end6 - begin6);
	printf("MergeSort2:%d\n", end10 - begin10);
	printf("BubbleSort:%d\n", end7 - begin7);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
	free(a10);
}

int main()
{

	testInsertSort();
	//testBubbleSort();
	testShellSort();
	//testQuickSort1();
	//testQuickSort2();
	//testQuickSort3();
	//testHeapSort();
	//testSelectSort();
	//testMergeSort1();
	//testMergeSort2();
	//testCountSort();
	//TestOP();

	return 0;

}