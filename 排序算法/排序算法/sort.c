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

//��������
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

//ϣ��������С��������
void ShellSort(int* a, int n)
{
	//gap>1  Ԥ����   gap = 1 ֱ�Ӳ�������
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

//ð�����򣨽�������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		//��־
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

//ѡ������  O(N^2)
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
		// 1��ѡ�����Һ�����С���Ǹ�
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// 2���������С�ڸ��ף��򽻻������������µ���
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

// O��logN*N��
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


//����ȡ��
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
		//��С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		//�Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	//��λ
	int pit = left;
	while(left < right)
	{
		//�ұ����� ��С
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[pit] = a[right];
		pit = right;
		//����Ҵ�
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

//ǰ��ָ�뷨
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

//��������
//��������ÿ��key������λ�� O(N*logN)
//������ÿ��key������С�������� O(N^2
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


//С�����Ż�
//�����Сʱ������ʹ�õݹ黮�ֵ�˼·�������򣬶���ֱ��ʹ�ò��������С�������򣬼��ٵݹ����
void QuickSort2(int* a, int begin, int end)
{
	// ���������ֻ��һ��ֵ���߲�������ô���ǵݹ������������
	if (begin >= end)
		return;

	// С����ֱ�Ӳ��������������
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

//�ǵݹ�
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

	//�鲢
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

//�鲢����
void MergeSort1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

//�鲢���� �ǵݹ�
void MergeSort2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;

	while (gap < n)
	{
		// ���Ϊgap��һ�飬�����鲢
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// end1 Խ�磬����
			if (end1 >= n)
				end1 = n - 1;

			// begin2 Խ�磬�ڶ������䲻����
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}

			// begin2 ok�� end2Խ�磬����end2����
			if (begin2 < n && end2 >= n)
				end2 = n - 1;

			// �����ϵ�
			if (begin1 == 8 && end1 == 9 && begin2 == 9 && end2 == 9)
			{
				int x = 0;
			}

			printf("�鲢[%d,%d][%d,%d]----%d\n", begin1, end1, begin2, end2, gap);

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


//��������
/*
ʱ�临�Ӷȣ�O(range+n)
�ռ临�Ӷȣ�O(range)
˵���������������ڷ�Χ�Ƚϼ��е�����
�������и���Ҳ����ʵ��
���������縡�������ַ����Ȳ���
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
	//��Χ
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	assert(countA);

	memset(countA, 0, sizeof(int)*range);

	//����
	for (int i = 0; i < n; i++)
	{
		countA[a[i] - min]++;
	}

	//����
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countA[i]--)
		{
			a[j++] = i + min;
		}
	}
}