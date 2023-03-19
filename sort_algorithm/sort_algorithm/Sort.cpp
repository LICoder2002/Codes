#pragma once
#include<stack>
#include<cassert>
#include "Sort.h"

//��������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//��ӡ����
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��������
/*
*���裺
* 1. �ӵ�һ��Ԫ�ؿ�ʼ����Ϊ��Ԫ���Ѿ����������Ҫѭ�� n - 1 ��
* 2. ȡ��һ��itemԪ�أ����Ѿ������Ԫ�����дӺ���ǰɨ��
* 3. �����ǰ��Ԫ�ش���item���ͽ���Ԫ���Ƶ���һλ
* 4. �ظ�����3��ֱ���ҵ�������Ԫ����С�ڵ���item��Ԫ��
* 5. ��itemԪ�ز��뵽��Ԫ�صĺ��棬��������������Ԫ�ض�����item����item���뵽 0 �±�λ��
* 6. �ظ����� 2��5�� ֱ������������Ԫ��
* 
* ʱ�临�Ӷȣ�������ΪO(N^2), ����ʱ�ӽ�����
*			  ��õ����ΪO(N), ����ʱΪ������߽ӽ�����
* 
* �ռ临�Ӷȣ�O(1)��
*/

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int item = arr[end + 1];
		while (end >= 0)
		{
			// ��� item С�ڵ�ǰԪ�أ��ͽ���ǰԪ������ƶ�һλ 
			if (item < arr[end]) 
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				// ��ʱitem���ڻ��ߵ��ڵ�ǰԪ�أ�����ѭ����������ڵ�ǰԪ��֮��
				break;
			}
		}
		arr[end + 1] = item;
	}
}


//ϣ������

/*
* ���裺
* 1. ��ѡ��һ��С��N������gap��Ϊ��һ������Ȼ�����о���Ϊgap��Ԫ�ط�Ϊͬһ�飬����ÿһ��Ԫ��ֱ��ʹ�ò�������Ȼ���ٽ�gap��ֵ��С���ظ�����������
* 2. ��gap��Ϊ1��ʱ�򣬾�������������б��ֳ���һ�飬����ڽ���ֱ�Ӳ������򣬵���ʱ���������Ѿ��ӽ�����
* 
* ʱ�临�Ӷȣ�O(N^1.3)��
* 
* �ռ临�Ӷȣ�O(1)��
*/
void ShellSort(int* arr, int n)
{
	//�� gap > 1 ʱ����ڽ���Ԥ���� �� gap = 1 ʱ��ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//��֤���gap = 1
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

//ѡ������
/*
* ˼·��
* ÿ�δӴ�����������ѡ��һ����Сֵ��Ȼ������������е�ĩλ�ã�ֱ��������ɼ��ɡ�
* ʵ����ÿ�ο���ͬʱѡ���һ����Сֵ�����ֵ���ֱ�������еĿ�ͷ�ͽ�β����������ʹ��ѡ�������Ч�ʿ���һ����
* 
* ʱ�临�Ӷȣ�O(N^2)��
* 
* �ռ临�Ӷȣ�O(1)��
*/

void SelectSort(int* arr, int n)
{
	//������뵥���������ʼ�ͽ���λ��
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//���ֵ�±�
		int maxi = begin;
		//��Сֵ�±�
		int mini = end;
		
		//�ҳ�������Сֵ���±�
		for (int i = begin; i < end; ++i)
		{
			if (arr[i] > arr[maxi])
				maxi = i;
			if (arr[i] < arr[mini])
				mini = i;
		}

		//��С��ֵ�ſ�ͷ
		Swap(&arr[mini], &arr[begin]);
		//��ʱ�����ԭ������λ����begin  ���磺9 7 2 3 --��maxi == begin == 0, mini == 2, end == 3 �����������maxi == begin�жϣ�����Ϊ 2 7 9 3 --��3 7 9 2��ʵ��Ӧ���� 2��7��3��9
		if (maxi == begin)
		{
			//����maxi
			maxi = mini;
		}
		//����ֵ�����
		Swap(&arr[maxi], &arr[end]);
		++begin; 
		--end;
	}
}

//ð������
/*
* ˼·��
* ѭ��һ�ˣ���ߴ����ұ�����н�����һ�˽��������ֵ���ұ�
* 
* ʱ�临�Ӷȣ����O(N^2)������
*			  ��ã�O(N)����������߽ӽ�����
* 
* �ռ临�Ӷȣ�O(1)��
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
			//һ��������û��Ԫ�ؽ��н�����˵���Ѿ�����
			break;
		}
		--end;
	}
}

//������

/**
* ������һ����ȫ���������ѷ�Ϊ����Ѻ�С���ѣ�
* ����ѣ����и��ڵ���ڵ��ں��ӽڵ�
* С���ѣ����и��ڵ�С�ڵ��ں��ӽڵ�
* 
* ����С�ѣ����򽨴��
*
*/


//����---��С��

/**
* ��������С�ѣ�����ѡ����Сֵ�����ڵ㣬��ÿ�ν��õ�С�ѵ����һ��Ҷ�ӽڵ�͸��ڵ���н�����
* �����󲻰����һ�������ɶ����������һֱѭ����ֱ��ʣ���һ������
*/

//��С�ѵ����µ����㷨
void SmallAdjustDown(int* arr, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1; //Ĭ������
	//���ӽڵ���±곬�������±�ͽ���
	while (child < n)
	{
		//�ҳ����Һ�����С���Ǹ�
		if ((child + 1) < n && arr[child + 1] < arr[child])//Ҫ�ж��Һ����Ƿ����
		{
			++child;
		}
		if (arr[child] < arr[parent])
		{
			//���child��Ӧֵ��parent��С�ͽ���
			Swap(&arr[child], &arr[parent]);
			//����parent��child���±�
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//�Ѿ�����С��
			break;
		}
	}

}

//��С�ѵ����ϵ����㷨
void SmallAdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent] && parent >= 0)
		{
			Swap(&arr[child], &arr[parent]);
			//����child��parent�±�
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//����С��
			break;
		}
	}
}


void _HeapSortDown(int * arr, int n)
{
	//ʹ�����齨С��
	//�ҵ�������һ����Ҷ�ӽڵ��λ�ý������µ�����Ȼ����ŵ��ǵڶ�����...ֱ�����һ�����ڵ㡣
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
	//����С�Ľ������ѵ����һ��λ�ã�����һ�����������ɶ��������
	while(end > 0)
	{
		Swap(&arr[end], &arr[0]);
		SmallAdjustDown(arr, end, 0);
		PrintArray(arr, n);
		--end;
	}
}

//=====================================================================
//����---�����
/*
* �������򽨴�ѣ�����ѡ������ֵ�����ڵ㣬��ÿ�ν��öѵ����һ��Ҷ�ӽڵ�͸��ڵ���н�����
* �����󲻰����һ�������ɶ����������һֱѭ����ֱ��ʣ���һ������
*/
//����ѵ����µ����㷨
void BigAdjustDown(int* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ����Һ��Ӵ����һ��
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			++child;
		}
		//������Ӵ��ڸ��ڵ��򽻻�
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

//����ѵ����ϵ����㷨
void BigAdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent] && parent >= 0)
		{
			Swap(&arr[child], &arr[parent]);
			//����child��parent�±�
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//����С��
			break;
		}
	}
}


//���� -- ���ϵ����㷨�汾
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

//��������

//1.hoare�汾---����ָ�뷨��ʱ�临�Ӷ�O(N*lgN)
/*
* ˼·��
* 1. ѡ��һ��key��һ��������߻������ұߡ�
* 2. ����һ��begin��end�����key����ߵģ�end���ƶ�������begin���ƶ���
* 3. ���ƶ������У�һ��end������keyС�ģ���ͣ�£�Ȼ��begin��ʼ�ƶ���ֱ��begin������key�����ͣ�£�����end��begin�����ݣ�Ȼ������ظ���ֱ��begin��end��������ʱ��key������
* 4. ��ʱkey��߶��Ǳ���С�ģ��ұ߶��Ǳ������
* 5. ��key�����������ڵݹ����ͬ��������ֱ���������в����ڻ���ֻ��һ�����ݡ�
*/

void _QuickSort1(int* arr, int begin, int end)
{
	//ֻ��һ�����������䲻����
	if (begin >= end)
		return;
	//��֤��ʱ����λ��
	int left = begin;
	int right = end;

	int keyi = begin; //ѡ�����Ϊkey

	while (begin < end)
	{
		//�ұ���С Ҫ��ֹbegin��end���
		while (arr[end] >= arr[keyi] && begin < end)
		{
			--end;
		}
		//����Ҵ�
		while (arr[begin] <= arr[keyi] && begin < end)
		{
			++begin;
		}
		//С�Ľ�������ߣ���Ľ������ұ�
		Swap(&arr[begin], &arr[end]);
	}

	//����key���������ֵ
	Swap(&arr[keyi], &arr[end]);
	keyi = end;
	//��ʱ���仮�� [left, keyi-1], keyi [keyi + 1, right]
	//�ݹ�
	_QuickSort1(arr, left, keyi - 1);
	_QuickSort1(arr, keyi + 1, right);
}

//2. �ڿӷ�
/*
* ˼·��hoare�汾����
* 1. ѡ��һ��������Ϊkey��һ������߻����ұߣ�Ȼ���λ���γ�һ����
* 2. ����һ��begin��end����������ߣ���end���ƶ�������begin���ƶ�
* 3. ���ƶ������У�end������keyС�ģ��򽫸���������У���Ȼ������ԭ����λ�þ��γ��˿ӣ�begin��ͬ��ֻ���ҵ��Ǳ�key��ģ����߽�����С���������֮�󣬽�key������С�
* 4. һ��ѭ���󣬴�ʱkey��߶��Ǳ���С�ģ��ұ߶��Ǳ������
* 5. ��key�����������ڵݹ����ͬ��������ֱ���������в����ڻ���ֻ��һ�����ݡ�
*/

//�ݹ�汾
void _QuickSort2_1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin, right = end;
	int key = arr[begin];

	while (begin < end)
	{
		//�ұ���С
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		//����Ҵ�
		while (arr[begin] <= key && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	//key������� begin == end
	arr[begin] = key;
	int keyi = begin;
	//���仮�֣�[left, keyi - 1], keyi, [keyi + 1, right] 
	_QuickSort2_1(arr, left, keyi - 1);
	_QuickSort2_1(arr, keyi + 1, right);
}

//�ǵݹ�汾

//��������
int _PartSort(int* arr, int begin, int end)
{
	int key = arr[begin];

	while (begin < end)
	{
		//�ұ���С
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		//����Ҵ�
		while (arr[begin] <= key && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	//key������� begin == end
	arr[begin] = key;
	//����λ��
	int meeti = begin;
	return meeti;
}

void _QuickSort2_2(int* arr, int begin, int end)
{
	std::stack<int> st;
	//�ұ�����ջ
	st.push(end);
	//Ȼ�������ջ
	st.push(begin);
	while (!st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		
		int midi = _PartSort(arr, left, end);
		//���仮�֣�[left, midi - 1], midi, [midi + 1, right]
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

//�鲢����
/*
* ˼·��
* 1. �ѳ���Ϊn�����з�Ϊ��������Ϊn/2��������
* 2. ���������������ڽ��еݹ黮�֣�ֱ�����ܻ���
* 3. ������õ������н��кϲ�
*/

void _MergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	//�������� [begin, mid], [mid + 1, end]
	int mid = (begin + end) / 2;
	//�ݹ黮��������
	_MergeSort(arr, begin, mid, tmp);
	_MergeSort(arr, mid + 1, end, tmp);

	//�鲢
	// 
	//����1
	int begin1 = begin, end1 = mid;
	//����2
	int begin2 = mid + 1, end2 = end;
	//printf("[%d, %d]  [%d, %d]\n", begin1, end1, begin2, end2);

	//tmp����ʼλ��
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

	//��ʱ���ܻ���һ�����б���һ�����г������
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	//��tmp������arr
	memcpy(arr + begin, tmp + begin, (static_cast<unsigned long long>(end) - begin + 1) * sizeof(int));
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

//��������
/**
* ˼·��
* 1. �ҳ�������Ԫ���е����ֵ����Сֵȷ������ķ�Χ
* 2. ͳ�������е�ÿ��ֵ���ֵĴ����������Count�����Ӧ��λ��
* 3. ����ڸ���Count���鷴�����ԭ����
* 
* ʱ�临�Ӷȣ�O(N + range)
* �ռ临�Ӷȣ�O(range)
*/
void CountSort(int* arr, int n)
{
	int min = arr[0], max = arr[0];
	//�ҳ����ֵ����Сֵ
	for (int i = 1; i < n; ++i)
	{
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	//ȷ�����Χ������Count���� 1�� 3�� 2�� 5 ��1 - 5 ���5�����ظ�Ԫ�� 5-1 + 1
	int range = max - min + 1;
	int* Count = (int*)malloc(sizeof(int) * range);
	assert(Count);

	memset(Count, 0, sizeof(int) * range);

	//����
	for (int i = 0; i < n; ++i)
	{
		Count[arr[i] - min] ++; 
	}

	//�������ԭ����
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
