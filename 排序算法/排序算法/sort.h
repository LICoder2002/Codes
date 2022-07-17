#include<stdio.h>
#include<stdlib.h>

void PrintArray(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//希尔排序（缩小增量排序）
void ShellSort(int* a, int n);

//冒泡排序（交换排序）
void BubbleSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//快速排序
void QuickSort1(int* a, int begin, int end);

//小区间优化快速排序
void QuickSort2(int* a, int begin, int end);

//非递归
void QuickSort3(int* a, int begin, int end);

//堆排序
void HeapSort(int* a, int n);

//归并排序
void MergeSort1(int* a, int n);

//归并排序 非递归
void MergeSort2(int* a, int n);


//计数排序
void CountSort(int* a, int n);