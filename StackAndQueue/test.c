#include"Stack.h"
#include"Queue.h"

void testStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 4);
	StackPush(&st, 3);
	StackPush(&st, 2);
	StackPush(&st, 1);
	StackPush(&st, 0);


	StackPush(&st, 2);
	StackPush(&st, 1);


	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);

	}
	printf("\n");
	StackDestory(&st);
}
void testQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestory(&q);
}

int main()
{
	//testStack();
	testQueue();
	return 0;
}