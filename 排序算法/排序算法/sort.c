#include"Stack.h"
#include"sort.h"
#include<string.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

//希尔排序（缩小增量排序）
void ShellSort(int* a, int n)
{
	//gap>1  预排序   gap = 1 直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap = n / 2 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}

}

//冒泡排序（交换排序）
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		//标志
		int flag = 0;

		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				flag = 1;
				Swap(&a[j - 1], &a[j]);
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

//选择排序  O(N^2)
void SelectSort(int* a, int n)
{
	int left = 0;;
	int right = n - 1;
	while (left < right)
	{
		int mini = left;
		int maxi = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[left], &a[mini]);
		if (left == maxi)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);

		left++;
		right--;
	}
}


void AdjustDown(int* a, size_t size, size_t root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		// 1、选出左右孩子中小的那个
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// 2、如果孩子小于父亲，则交换，并继续往下调整
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// O（logN*N）
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


//三数取中
int GetMidIndex(int* a, int left, int right)
{
	//int mid = (left + right) / 2;
	int mid = left + (right - left) / 2;
	//left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left]>a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}

}

//hoare
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	//坑位
	int pit = left;
	while(left < right)
	{
		//右边先走 找小
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[pit] = a[right];
		pit = right;
		//左边找大
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[pit] = a[left];
		pit = left;
	}
	a[pit] = key;
	return pit;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && a[++prev] != a[cur])
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
	
	//int keyi = right;
	//int prev = left - 1, cur = left;
	//while (cur < right)
	//{
	//	if (a[cur] < a[keyi] && a[++prev] != a[cur])
	//	{
	//		Swap(&a[prev], &a[cur]);
	//	}
	//	cur++;
	//}
	//Swap(&a[keyi], &a[++prev]);
	//return prev;
}

//快速排序
//最好情况：每次key都是中位数 O(N*logN)
//最坏情况：每次key都是最小或者最大的 O(N^2
void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	//int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	int keyi = PartSort3(a, begin, end);

	QuickSort1(a, begin, keyi - 1);
	QuickSort1(a, keyi + 1, end);
}


//小区间优化
//区间很小时，不再使用递归划分的思路让其有序，而是直接使用插入排序对小区间排序，减少递归调用
void QuickSort2(int* a, int begin, int end)
{
	// 子区间相等只有一个值或者不存在那么就是递归结束的子问题
	if (begin >= end)
		return;

	// 小区间直接插入排序控制有序
	if (end - begin + 1 <= 10)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int keyi = PartSort3(a, begin, end);
		// [begin, keyi-1]keyi[keyi+1, end]
		QuickSort2(a, begin, keyi - 1);
		QuickSort2(a, keyi + 1, end);
	}

}

//非递归
void QuickSort3(int* a, int begin, int end)
{
	ST s;
	StackInit(&s);
	StackPush(&s, begin);
	StackPush(&s, end);

	while (!StackEmpty(&s))
	{
		int right = StackTop(&s);
		StackPop(&s);
		int left = StackTop(&s);
		StackPop(&s);

		int keyi = PartSort2(a, left, right);

		if (left < keyi - 1)
		{
			StackPush(&s, left);
			StackPush(&s, keyi - 1);
		}
		if (keyi + 1 < right)
		{
			StackPush(&s, keyi + 1);
			StackPush(&s, right);
		}
	}
	StackDestory(&s);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//[begin,mid]  [mid+1,end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));

}

//归并排序
void MergeSort1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

//归并排序 非递归
void MergeSort2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;

	while (gap < n)
	{
		// 间距为gap是一组，两两归并
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// end1 越界，修正
			if (end1 >= n)
				end1 = n - 1;

			// begin2 越界，第二个区间不存在
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}

			// begin2 ok， end2越界，修正end2即可
			if (begin2 < n && end2 >= n)
				end2 = n - 1;

			// 条件断点
			if (begin1 == 8 && end1 == 9 && begin2 == 9 && end2 == 9)
			{
				int x = 0;
			}

			printf("归并[%d,%d][%d,%d]----%d\n", begin1, end1, begin2, end2, gap);

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}

			while (begin1 <= end1)
				tmp[index++] = a[begin1++];

			while (begin2 <= end2)
				tmp[index++] = a[begin2++];
		}
		memcpy(a, tmp, n * sizeof(int));
		//PrintArray(a, n);

		gap *= 2;
	}

	free(tmp);
}


//计数排序
/*
时间复杂度：O(range+n)
空间复杂度：O(range)
说明计数排序适用于范围比较集中的数据
数组中有复数也可以实现
其他类型如浮点数，字符串等不行
*/
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	//范围
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	assert(countA);

	memset(countA, 0, sizeof(int)*range);

	//计算
	for (int i = 0; i < n; i++)
	{
		countA[a[i] - min]++;
	}

	//排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countA[i]--)
		{
			a[j++] = i + min;
		}
	}
}