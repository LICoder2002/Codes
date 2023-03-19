#include "Sort.h"


void TestInsertSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, len);
	PrintArray(arr, len);
}

void TestShellSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, len);
	PrintArray(arr, len);
}

void TestSelectSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);
	PrintArray(arr, len);
}

void TestBubbleSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	PrintArray(arr, len);
}


void TestHeapSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, len);
	//PrintArray(arr, len);
}

void TestQuickSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, len);
	PrintArray(arr, len);
}

void TestCountSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, len);
	PrintArray(arr, len);
}

void TestMergeSort()
{
	int arr[] = { 9, 5, 3, 7, 1, 8, 2, 6, 0, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, len);
	PrintArray(arr, len);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestHeapSort();
	//TestQuickSort();
	//TestCountSort();
	TestMergeSort();
	return 0;
}