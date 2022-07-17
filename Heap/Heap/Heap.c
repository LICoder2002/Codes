#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void HeapPrint(HP* php)
{
	assert(php);
	for (size_t i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void AdjustUp(HPDataType* a, size_t child)
{
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
			//if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		size_t newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}

		php->a = tmp;
		php->capacity = newCapacity;
	}

	php->a[php->size] = x;
	++php->size;

	// 向上调整，控制保持是一个小堆
	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType* a, size_t size, size_t root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		// 1、选出左右孩子中小的那个
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}

		// 2、如果孩子小于父亲，则交换，并继续往下调整
		if (a[child] < a[parent])
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

// 删除堆顶的数据。(最小/最大)
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	--php->size;

	AdjustDown(php->a, php->size, 0);
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}