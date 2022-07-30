#include"stack.h"
#include"queue.h"
using namespace lhf;
#include<iostream>
#include<vector>
#include<list>
using std::cout;
using std::endl;

void testStack()
{
	cout << "testStack()" << endl;
	stack<int>st;
	//stack<int, std::vector<int>> st;
	//stack<int, std::string>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void testQueue()
{
	cout << "testQueue()" << endl;

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priority_queue()
{
	priority_queue<int> pq;
	//priority_queue<int, std::vector<int>, greater<int>>pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void test_priority_queue2()
{
	int a[] = { 1, 4, 2, 7, 8, 9 };
	priority_queue<int> pq(a, a + 6);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	testStack();
	testQueue();

	test_priority_queue2();


	return 0;
}