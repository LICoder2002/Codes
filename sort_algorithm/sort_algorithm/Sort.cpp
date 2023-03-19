#pragma once
#include<stack>
#include<cassert>
#include "Sort.h"

//交换函数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//打印数组
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//插入排序
/*
*步骤：
* 1. 从第一个元素开始，认为该元素已经有序，因此需要循环 n - 1 次
* 2. 取下一个item元素，从已经排序的元素序列从后往前扫描
* 3. 如果当前的元素大于item，就将该元素移到下一位
* 4. 重复步骤3，直到找到已排序元素中小于等于item的元素
* 5. 将item元素插入到该元素的后面，如果已排序的所有元素都大于item，则将item插入到 0 下标位置
* 6. 重复步骤 2—5， 直到排序完所有元素
* 
* 时间复杂度：最坏的情况为O(N^2), 即此时接近逆序；
*			  最好的情况为O(N), 即此时为有序或者接近有序。
* 
* 空间复杂度：O(1)。
*/

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int item = arr[end + 1];
		while (end >= 0)
		{
			// 如果 item 小于当前元素，就将当前元素向后移动一位 
			if (item < arr[end]) 
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				// 此时item大于或者等于当前元素，跳出循环，将其放在当前元素之后
				break;
			}
		}
		arr[end + 1] = item;
	}
}


//希尔排序

/*
* 步骤：
* 1. 先选择一个小于N的整数gap作为第一增量，然后将所有距离为gap的元素分为同一组，并对每一组元素直接使用插入排序，然后再将gap的值缩小，重复上述操作。
* 2. 当gap变为1的时候，就相对于整个序列被分成了一组，相对于进行直接插入排序，但此时整个序列已经接近有序。
* 
* 时间复杂度：O(N^1.3)。
* 
* 空间复杂度：O(1)。
*/
void ShellSort(int* arr, int n)
{
	//当 gap > 1 时相对于进行预排序， 当 gap = 1 时，直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//保证最后gap = 1
		//gap = gap / 2 + 1;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int item = arr[end + gap];
			while (end >= 0)
			{
				if (item < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = item;
		}
	}
}

//选择排序
/*
* 思路：
* 每次从待排序序列中选出一个最小值，然后放在有序序列的末位置，直到排序完成即可。
* 实际上每次可以同时选择出一个最小值和最大值，分别放在序列的开头和结尾，这样可以使得选择排序的效率快上一倍。
* 
* 时间复杂度：O(N^2)。
* 
* 空间复杂度：O(1)。
*/

void SelectSort(int* arr, int n)
{
	//保存参与单趟排序的起始和结束位置
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//最大值下标
		int maxi = begin;
		//最小值下标
		int mini = end;
		
		//找出最大和最小值的下标
		for (int i = begin; i < end; ++i)
		{
			if (arr[i] > arr[maxi])
				maxi = i;
			if (arr[i] < arr[mini])
				mini = i;
		}

		//最小的值放开头
		Swap(&arr[mini], &arr[begin]);
		//此时，如果原来最大的位置是begin  例如：9 7 2 3 --》maxi == begin == 0, mini == 2, end == 3 ，如果不进行maxi == begin判断，则结果为 2 7 9 3 --》3 7 9 2，实际应该是 2，7，3，9
		if (maxi == begin)
		{
			//更新maxi
			maxi = mini;
		}
		//最大的值放最后
		Swap(&arr[maxi], &arr[end]);
		++begin; 
		--end;
	}
}

//冒泡排序
/*
* 思路：
* 循环一趟，左边大于右边则进行交换，一趟结束后，最大值在右边
* 
* 时间复杂度：最坏，O(N^2)，逆序。
*			  最好，O(N)，即有序或者接近有序
* 
* 空间复杂度：O(1)。
*/
void BubbleSort(int* arr, int n)
{
	int end = n;
	while (end)
	{
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			//一趟下来，没有元素进行交换，说明已经有序
			break;
		}
		--end;
	}
}

//堆排序

/**
* 堆总是一个完全二叉树，堆分为大根堆和小根堆：
* 大根堆：所有父节点大于等于孩子节点
* 小根堆：所有父节点小于等于孩子节点
* 
* 降序建小堆，升序建大堆
*
*/


//降序---建小堆

/**
* 降序排序建小堆，可以选出最小值即根节点，将每次建好的小堆的最后一个叶子节点和根节点进行交换，
* 交换后不把最后一个数看成堆里面的数，一直循环，直到剩最后一个数。
*/

//建小堆的向下调整算法
void SmallAdjustDown(int* arr, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1; //默认左孩子
	//孩子节点的下标超过数组下标就结束
	while (child < n)
	{
		//找出左右孩子中小的那个
		if ((child + 1) < n && arr[child + 1] < arr[child])//要判断右孩子是否存在
		{
			++child;
		}
		if (arr[child] < arr[parent])
		{
			//如果child对应值比parent的小就交换
			Swap(&arr[child], &arr[parent]);
			//跟新parent和child的下标
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//已经满足小堆
			break;
		}
	}

}

//建小堆的向上调整算法
void SmallAdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent] && parent >= 0)
		{
			Swap(&arr[child], &arr[parent]);
			//更新child和parent下标
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//满足小堆
			break;
		}
	}
}


void _HeapSortDown(int * arr, int n)
{
	//使用数组建小堆
	//找到倒数第一个非叶子节点的位置进行向下调整，然后接着倒是第二、三...直到最后一个根节点。
	//for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	//{
	//	SmallAdjustDown(arr, n, i);
	//}
	for (int i = 1; i < n; ++i)
	{
		SmallAdjustUp(arr, i);
	}
	PrintArray(arr, n);

	int end = n - 1;
	//把最小的交换到堆的最后一个位置，并下一处调整不看成堆里面的数
	while(end > 0)
	{
		Swap(&arr[end], &arr[0]);
		SmallAdjustDown(arr, end, 0);
		PrintArray(arr, n);
		--end;
	}
}

//=====================================================================
//升序---建大堆
/*
* 升序排序建大堆，可以选出最大的值即根节点，将每次建好堆的最后一个叶子节点和根节点进行交换，
* 交换后不把最后一个数看成堆里面的数，一直循环，直到剩最后一个数。
*/
//建大堆的向下调整算法
void BigAdjustDown(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出左右孩子大的那一个
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			++child;
		}
		//如果孩子大于父节点则交换
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//建大堆的向上调整算法
void BigAdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent] && parent >= 0)
		{
			Swap(&arr[child], &arr[parent]);
			//更新child和parent下标
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//满足小堆
			break;
		}
	}
}


//升序 -- 向上调整算法版本
void _HeapSortUp(int* arr, int n)
{
	//for (int i = (n - 1 - 1) / 2; i >= 0; --i) //O(lgN)
	//{
	//	BigAdjustDown(arr, n, i);
	//}
	for (int i = 1; i < n; ++i) //O(N)
	{
		BigAdjustUp(arr, i);
	}
	PrintArray(arr, n);

	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[end], &arr[0]);
		BigAdjustDown(arr, end, 0);
		PrintArray(arr, n);
		--end;
	}
}

void HeapSort(int* arr, int n)
{	
	_HeapSortDown(arr, n);
	//_HeapSortUp(arr, n);
}

//快速排序

//1.hoare版本---左右指针法，时间复杂度O(N*lgN)
/*
* 思路：
* 1. 选出一个key，一般是最左边或者最右边。
* 2. 定义一个begin和end，如果key是左边的，end先移动，否则begin先移动。
* 3. 在移动过程中，一个end遇到比key小的，则停下，然后begin开始移动，直到begin遇到比key大的则停下，交换end和begin的内容，然后继续重复，直到begin和end相遇，此时与key交换。
* 4. 此时key左边都是比它小的，右边都是比它大的
* 5. 将key的左右序列在递归进行同样的排序，直到左右序列不存在或者只有一个数据。
*/

void _QuickSort1(int* arr, int begin, int end)
{
	//只有一个数或者区间不存在
	if (begin >= end)
		return;
	//保证此时左右位置
	int left = begin;
	int right = end;

	int keyi = begin; //选择左边为key

	while (begin < end)
	{
		//右边找小 要防止begin和end错过
		while (arr[end] >= arr[keyi] && begin < end)
		{
			--end;
		}
		//左边找大
		while (arr[begin] <= arr[keyi] && begin < end)
		{
			++begin;
		}
		//小的交换到左边，大的交换到右边
		Swap(&arr[begin], &arr[end]);
	}

	//交换key与相遇点的值
	Swap(&arr[keyi], &arr[end]);
	keyi = end;
	//此时区间划分 [left, keyi-1], keyi [keyi + 1, right]
	//递归
	_QuickSort1(arr, left, keyi - 1);
	_QuickSort1(arr, keyi + 1, right);
}

//2. 挖坑法
/*
* 思路和hoare版本相似
* 1. 选出一个数据作为key，一般是左边或者右边，然后该位置形成一个坑
* 2. 定义一个begin和end，做坑在左边，则end先移动，否则begin先移动
* 3. 在移动过程中，end遇到比key小的，则将该数据填到坑中，自然该数据原来的位置就形成了坑，begin则同理，只是找的是比key大的，二者交替进行。二者相遇之后，将key填入坑中。
* 4. 一趟循环后，此时key左边都是比它小的，右边都是比它大的
* 5. 将key的左右序列在递归进行同样的排序，直到左右序列不存在或者只有一个数据。
*/

//递归版本
void _QuickSort2_1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin, right = end;
	int key = arr[begin];

	while (begin < end)
	{
		//右边找小
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		//左边找大
		while (arr[begin] <= key && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	//key回填到坑中 begin == end
	arr[begin] = key;
	int keyi = begin;
	//区间划分：[left, keyi - 1], keyi, [keyi + 1, right] 
	_QuickSort2_1(arr, left, keyi - 1);
	_QuickSort2_1(arr, keyi + 1, right);
}

//非递归版本

//单趟排序
int _PartSort(int* arr, int begin, int end)
{
	int key = arr[begin];

	while (begin < end)
	{
		//右边找小
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		//左边找大
		while (arr[begin] <= key && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	//key回填到坑中 begin == end
	arr[begin] = key;
	//相遇位置
	int meeti = begin;
	return meeti;
}

void _QuickSort2_2(int* arr, int begin, int end)
{
	std::stack<int> st;
	//右边先入栈
	st.push(end);
	//然后左边入栈
	st.push(begin);
	while (!st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		
		int midi = _PartSort(arr, left, end);
		//区间划分：[left, midi - 1], midi, [midi + 1, right]
		if (left < midi - 1)
		{
			st.push(midi - 1);
			st.push(left);
		}
		if (midi + 1 < right)
		{
			st.push(right);
			st.push(midi + 1);
		}
	}
}


void QuickSort(int* arr, int n)
{
	//_QuickSort1(arr, 0, n - 1);
	//_QuickSort2_1(arr, 0, n - 1);
	_QuickSort2_2(arr, 0, n - 1);
}

//归并排序
/*
* 思路：
* 1. 把长度为n的序列分为两个长度为n/2的子序列
* 2. 对这两个子序列在进行递归划分，直到不能划分
* 3. 对排序好的子序列进行合并
*/

void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	//划分区间 [begin, mid], [mid + 1, end]
	int mid = (begin + end) / 2;
	//递归划分子区间
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid + 1, end, tmp);

	//归并
	// 
	//区间1
	int begin1 = begin, end1 = mid;
	//区间2
	int begin2 = mid + 1, end2 = end;
	//printf("[%d, %d]  [%d, %d]\n", begin1, end1, begin2, end2);

	//tmp的起始位置
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	//此时可能会有一个序列比另一个序列长的情况
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	//将tmp拷贝给arr
	memcpy(arr + begin, tmp + begin, (static_cast<unsigned long long>(end) - begin + 1) * sizeof(int));
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//计数排序
/**
* 思路：
* 1. 找出待排序元素中的最大值和最小值确定排序的范围
* 2. 统计数组中的每个值出现的次数并存放在Count数组对应的位置
* 3. 最后在根据Count数组反向填充原数组
* 
* 时间复杂度：O(N + range)
* 空间复杂度：O(range)
*/
void CountSort(int* arr, int n)
{
	int min = arr[0], max = arr[0];
	//找出最大值和最小值
	for (int i = 1; i < n; ++i)
	{
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	//确定最大范围，创建Count数组 1， 3， 2， 5 ：1 - 5 最多5个不重复元素 5-1 + 1
	int range = max - min + 1;
	int* Count = (int*)malloc(sizeof(int) * range);
	assert(Count);

	memset(Count, 0, sizeof(int) * range);

	//计数
	for (int i = 0; i < n; ++i)
	{
		Count[arr[i] - min] ++; 
	}

	//反向填充原数组
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (Count[i]--)
		{
			arr[j++] = i + min;
		}
	}

	free(Count);
}
